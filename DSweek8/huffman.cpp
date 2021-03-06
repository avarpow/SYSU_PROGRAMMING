#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <map>

using namespace std;

string str_input; //储存整个文件的字符串
string str_zip;
string huffman_map[256];
struct zip_huffman_node
{
    char c;
    int count;
    zip_huffman_node *left_child, *right_child, *parent;
    bool friend operator<(zip_huffman_node a, zip_huffman_node b)
    {
        return a.count > b.count;
    }
};

void openfile(string inputfile_name, string &str_input)
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
void count_huffman_node(vector<int> &huffman_count, const string &str_input)
{
    huffman_count.resize(256);
    for (auto &i : str_input)
    {
        huffman_count[i]++;
    }
    for (int i = 0; i < 256; i++)
    {
        cout << i << " : " << huffman_count[i] << endl;
    }
}
void createheap(const vector<int> &huffman_count, priority_queue<zip_huffman_node> &heap_huffman)
{
    for (int i = 0; i < 256; i++)
    {
        if (huffman_count[i] != 0)
        {
            zip_huffman_node t;
            t.c = i;
            t.count = huffman_count[i];
            t.left_child = t.right_child = t.parent = NULL;
            heap_huffman.push(t);
        }
    }
}
zip_huffman_node *createtree(priority_queue<zip_huffman_node> &heap_huffman)
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
void printtree(zip_huffman_node *root)
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
            cout << now_layel << " : " << temp->count;
            if (temp->left_child == NULL && temp->right_child == NULL)
            {
                cout << " " << (int)temp->c << "  leave node  ";
            }
            cout << endl;
            if (temp->left_child != NULL)
            {
                te.push(temp->left_child);
            }
            if (temp->right_child != NULL)
            {
                te.push(temp->right_child);
            }
            te.pop();
        }
    }
    //printtree ok 2020.10.22
}
void travel(zip_huffman_node *root, string &st)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left_child == NULL && root->right_child == NULL)
    {
        cout << (int)root->c << " " << root->c << " " << st << endl;
        huffman_map[root->c] = st;
        return;
    }
    if (root->left_child != NULL)
    {
        st.push_back('0');
        travel(root->left_child, st);
        st.erase(st.end() - 1);
    }
    if (root->right_child != NULL)
    {
        st.push_back('1');
        travel(root->right_child, st);
        st.erase(st.end() - 1);
    }
}
void trans2code(zip_huffman_node *root)
{
    //中序遍历，用栈
    string st;
    travel(root, st);
}
void genzipstr(string huffman_map[], string str_input, string &str_zip)
{
    for (auto &i : str_input)
    {
        str_zip += huffman_map[i];
    }
    cout << str_zip;
}
// void zipfile();
// void writefile();
void writezipfile(string &str_zip, string inputfile_name)
{
    string zipfile_name = inputfile_name + "_zip";
    ofstream s_zipfile;
    s_zipfile.open(zipfile_name, ios::out);
    if (!s_zipfile.is_open())
        return;
    int count = 0;
    char temp = 0;
    cout<<endl;
    for (auto &i : str_zip)
    {
        temp *= 2;
        temp += (i - '0');
        count++;
        cout<<i;
        if (count == 8)
        {
            cout <<" "<< hex << (short)temp;
            cout<<endl;
            s_zipfile << temp;
            temp = 0;
            count = 0;
        }
    }
}
void writekeyfile(string huffman_map[], int chunk, string inputfile_name)
{
    string keyfile_name = inputfile_name + "_key";
    cout << keyfile_name << endl;
    ofstream s_keyfile;
    s_keyfile.open(keyfile_name, ios::out);
    if (!s_keyfile.is_open())
        return;
    s_keyfile << chunk << endl;
    int vaild_key_count=0;
    for (int i = 0; i < 256; i++)
    {
        if(huffman_map[i]!="")
        vaild_key_count++;
    }
    s_keyfile<<vaild_key_count<<endl;
    for (int i = 0; i < 256; i++)
    {
        if (huffman_map[i] != "")
        {
            s_keyfile << i << " " << huffman_map[i] << endl;
        }
    }
    cout << "writekeyfile" << endl;
}
void writefile(string huffman_map[], string &str_zip, string inputfile_name)
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
void release_huffman_tree(zip_huffman_node *root)
{
    if(root==NULL ){
        return;
    }
    zip_huffman_node *now=root;
    release_huffman_tree(root->right_child);
    release_huffman_tree(root->left_child);
    delete now;
}
int main()
{
    string inputfile_name = "nozip";
    vector<int> huffman_count;
    priority_queue<zip_huffman_node> heap_huffman;
    zip_huffman_node *root;
    openfile(inputfile_name, str_input);
    count_huffman_node(huffman_count, str_input);
    createheap(huffman_count, heap_huffman);
    root = createtree(heap_huffman);
    printtree(root);
    trans2code(root);
    genzipstr(huffman_map, str_input, str_zip);
    writefile(huffman_map, str_zip, inputfile_name);
    release_huffman_tree(root);
    return 0;
}
