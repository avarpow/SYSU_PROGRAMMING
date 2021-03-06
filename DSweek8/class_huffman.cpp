#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <map>

using namespace std;

struct zip_huffman_node
{
    unsigned char c;
    int count;
    zip_huffman_node *left_child, *right_child, *parent;
    bool friend operator<(zip_huffman_node a, zip_huffman_node b)
    {
        return a.count > b.count;
    }
};
class zip_huffman
{
public:
    void setinputfile_name(string);//设置输入文件的文件名
    void setoutputfile_name(string);//设置输出生成的压缩文件的文件名
    void run();//执行压缩过程

private:
    string str_input; //储存整个文件的字符串
    string str_zip;//储存压缩之后的字符串
    string huffman_map[256];//储存每个字节对应的前缀码
    string inputfile_name;//储存输入文件的名
    string outputfile_name;//储存输出文件名
    string keyfile_name;//储存解压信息的文件名，为输出文件名+".key"
    vector<int> huffman_count;//统计每个字节的频次
    priority_queue<zip_huffman_node> heap_huffman;//暂时储存huffman节点的最小堆
    zip_huffman_node *root;//储存huffman树的根节点
    void openfile(string inputfile_name, string &str_input);//读取文件储存到字符串中
    void count_huffman_node(vector<int> &huffman_count, const string &str_input);//统计字节出现的频数
    void createheap(const vector<int> &huffman_count, priority_queue<zip_huffman_node> &heap_huffman);//建立huffman节点临时堆
    zip_huffman_node *createtree(priority_queue<zip_huffman_node> &heap_huffman);//建立huffman树
    void printtree(zip_huffman_node *root);//打印huffman树,debug用
    void travel(zip_huffman_node *root, string &st);//打印huffman节点的临时函数
    void trans2code(zip_huffman_node *root);//打印huffman节点的临时函数
    void genzipstr(string huffman_map[], string &str_input, string &str_zip);//生成压缩后的字符串
    void writezipfile(string &str_zip, string inputfile_name);//写入压缩后的文件
    void writekeyfile(string huffman_map[], int chunk, string inputfile_name);//写入压缩信息的文件
    void writefile(string huffman_map[], string &str_zip, string inputfile_name);//写入文件，调用前两个函数
    void release_huffman_tree(zip_huffman_node *root);//删除huffman树，防止内存泄漏
};
//设置输入文件的文件名
void zip_huffman::setinputfile_name(string _inputfile_name)
{
    inputfile_name = _inputfile_name;
}
//设置输出生成的压缩文件的文件名
void zip_huffman::setoutputfile_name(string _outputfile_name)
{
    outputfile_name = _outputfile_name;
}
//执行压缩过程
void zip_huffman::openfile(string inputfile_name, string &str_input)
{
    ifstream s_inputfile;
    s_inputfile.open(inputfile_name, ios::in | ios::binary);
    while (!s_inputfile.is_open())
    {
        return;
    }
    while (s_inputfile.peek() != EOF)
    {
        char t[1];
        s_inputfile.read(t, 1);
        str_input.push_back(t[0]);
    }
    //cout<<str_input;
    //10.21 19:53 str无错误
}
//统计字节出现的频数
void zip_huffman::count_huffman_node(vector<int> &huffman_count, const string &str_input)
{
    huffman_count.resize(256);
    for (auto &i : str_input)
    {
        unsigned char t=i;
        huffman_count[t]++;
    }
    for (int i = 0; i < 256; i++)
    {
        //cout << i << " : " << huffman_count[i] << endl;
    }
}
//建立huffman节点临时堆
void zip_huffman::createheap(const vector<int> &huffman_count, priority_queue<zip_huffman_node> &heap_huffman)
{
    for (int i = 0; i < 256; i++)
    {
        if (huffman_count[i] != 0)
        {
            zip_huffman_node t;
            t.c = i;
            t.count = huffman_count[i];
            t.left_child = t.right_child = t.parent = nullptr;
            heap_huffman.push(t);
        }
    }
}
//建立huffman树
zip_huffman_node *zip_huffman::createtree(priority_queue<zip_huffman_node> &heap_huffman)
{
    while (heap_huffman.size() > 1)
    {
        zip_huffman_node *tnode = new zip_huffman_node();
        zip_huffman_node *firstnode = new zip_huffman_node();
        zip_huffman_node *secnode = new zip_huffman_node();
        *firstnode = heap_huffman.top();
        heap_huffman.pop();
        *secnode = heap_huffman.top();
        heap_huffman.pop();
        tnode->left_child = firstnode;
        tnode->right_child = secnode;
        secnode->parent = tnode;
        firstnode->parent = tnode;
        tnode->count = firstnode->count + secnode->count;
        heap_huffman.push(*tnode);
    }
    zip_huffman_node *ret = new zip_huffman_node();
    *ret = heap_huffman.top();
    return ret;
}
//打印huffman树,debug用
void zip_huffman::printtree(zip_huffman_node *root)
{
    queue<zip_huffman_node *> te;
    int now_layel = 0;
    int all_count = 0;
    te.push(root);
    while (!te.empty())
    {
        int k = te.size();
        now_layel++;
        for (int i = 0; i < k; i++)
        {
            all_count++;
            zip_huffman_node *temp = te.front();
            //cout << now_layel << " : " << temp->count;
            if (temp->left_child == nullptr && temp->right_child == nullptr)
            {
                //cout << " " << (int)temp->c << "  leave node  ";
            }
            //cout << endl;
            if (temp->left_child != nullptr)
            {
                te.push(temp->left_child);
            }
            if (temp->right_child != nullptr)
            {
                te.push(temp->right_child);
            }
            te.pop();
        }
    }
    //printtree ok 2020.10.22
}
//根据huffman树，构建各个字符的前缀码
void zip_huffman::travel(zip_huffman_node *root, string &st)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left_child == nullptr && root->right_child == nullptr)
    {
        //cout << (int)root->c << " " << (int)root->c << " " << st << endl;
        huffman_map[root->c] = st;

        return;
    }
    if (root->left_child != nullptr)
    {
        st.push_back('0');
        travel(root->left_child, st);
        st.erase(st.end() - 1);
    }
    if (root->right_child != nullptr)
    {
        st.push_back('1');
        travel(root->right_child, st);
        st.erase(st.end() - 1);
    }
}
//打印huffman节点的临时函数
void zip_huffman::trans2code(zip_huffman_node *root)
{
    //中序遍历，用栈
    string st;
    travel(root, st);
}
//生成压缩后的字符串
void zip_huffman::genzipstr(string huffman_map[], string &str_input, string &str_zip)
{
    //cout<<"input str size"<<str_input.size()<<endl;
    for (auto i : str_input)
    {
        unsigned char t=i;
        str_zip += huffman_map[t];
    }
    //cout << str_zip;

}
//写入压缩后的文件
void zip_huffman::writezipfile(string &str_zip, string inputfile_name)
{
    string zipfile_name = outputfile_name;
    ofstream s_zipfile;
    s_zipfile.open(zipfile_name, ios::out|ios::binary);
    if (!s_zipfile.is_open())
        return;
    int count = 0;
    char temp = 0;
    //cout << endl;
    for (auto &i : str_zip)
    {
        temp *= 2;
        temp += (i - '0');
        count++;
        //cout << i;
        if (count == 8)
        {
            //cout << " " << hex << (short)temp;
            //cout << endl;
            s_zipfile << temp;
            temp = 0;
            count = 0;
        }
    }
}
//写入压缩信息的文件
void zip_huffman::writekeyfile(string huffman_map[], int chunk, string inputfile_name)
{
    string keyfile_name = outputfile_name + ".key";
    //cout << keyfile_name << endl;
    ofstream s_keyfile;
    s_keyfile.open(keyfile_name, ios::out|ios::binary);
    if (!s_keyfile.is_open())
        return;
    s_keyfile << chunk << endl;
    int vaild_key_count = 0;
    for (int i = 0; i < 256; i++)
    {
        if (huffman_map[i] != "")
            vaild_key_count++;
    }
    s_keyfile << vaild_key_count << endl;
    for (int i = 0; i < 256; i++)
    {
        if (huffman_map[i] != "")
        {
            s_keyfile << i << " " << huffman_map[i] << endl;
        }
    }
    //cout << "writekeyfile" << endl;
}
//写入文件，调用前两个函数
void zip_huffman::writefile(string huffman_map[], string &str_zip, string inputfile_name)
{
    //补充0到能被八个比特整除
    int chunk = (8 - str_zip.size() % 8) % 8;
    for (int i = 0; i < chunk; i++)
    {
        str_zip.push_back('0');
    }
    writezipfile(str_zip, inputfile_name);
    writekeyfile(huffman_map, chunk, inputfile_name);
}
//删除huffman树，防止内存泄漏
void zip_huffman::release_huffman_tree(zip_huffman_node *root)
{
    if (root == nullptr)
        return;
    zip_huffman_node *now = root;
    release_huffman_tree(root->right_child);
    release_huffman_tree(root->left_child);
    delete now;
}
//执行压缩过程
void zip_huffman::run()
{
    openfile(inputfile_name, str_input);
    count_huffman_node(huffman_count, str_input);
    createheap(huffman_count, heap_huffman);
    root = createtree(heap_huffman);
    printtree(root);
    trans2code(root);
    genzipstr(huffman_map, str_input, str_zip);
    writefile(huffman_map, str_zip, inputfile_name);
    release_huffman_tree(root);
    cout<<"                 ZIP OK! "<<endl;
    cout<<"   generate file: \""<<outputfile_name<<"\""<<endl;
    cout<<"  zipfile length: "<<str_zip.size()/8<<" bytes"<<endl;
    cout<<"unzipfile length: "<<str_input.size()<<" bytes"<<endl;
}
int main()
{
    zip_huffman test1;
    string input,output;
    cout<<"input the filename to be zip :";
    cin>>input;
    cout<<"input the output filename: ";
    cin>>output;
    test1.setinputfile_name(input);
    test1.setoutputfile_name(output);
    test1.run();
    return 0;
}
