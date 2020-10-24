#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <map>

using namespace std;

string huffman_map[256];//储存字节对应的前缀码
struct unzip_huffman_node
{
    unsigned char c;
    bool leave;//判断是否是根节点
    unzip_huffman_node *left_child, *right_child;
    unzip_huffman_node()
    {
        left_child = NULL;
        right_child = NULL;
        leave = false;
    }
    unzip_huffman_node(unzip_huffman_node *left, unzip_huffman_node *right, bool isleave, char ch)
    {
        left_child = left;
        right_child = right;
        leave = isleave;
        c = ch;
    }
};
class unzip_huffman
{
public:
    void setzipfile_name(string);//设置压缩文件文件名
    void setunzipfile_name(string);//设置解压得到文件名
    void setkeyfile_name(string);//设置解压得到文件名
    void run();//

private:
    int chunk;//标记压缩后补了多少个零
    string huffman_map[256];//每个字符的前缀编码
    string zipfile_name;//压缩文件名
    string unzipfile_name;//解压得到的文件名
    string keyfile_name;//解压信息的文件名
    string zip_str;//压缩的字符串
    string unzip_str;//解压后字符串
    unzip_huffman_node *root;//huffman树的根节点
    void constructHuffmanMap(string &keyfile_name, string huffman_map[], int &chunk);//
    void readZipstr(string &zipfile_name, string &zip_str, int chunk);//
    void readZipfile(string &zipfile_name, string &keyfile_name, string &zip_str);//
    void recreateHuffmanTree(string huffman_map[], unzip_huffman_node *root);//
    void unzipFile(string &zip_str, string huffman_map[], string &unzip_str, unzip_huffman_node *root);//
    void printTree(unzip_huffman_node *root);//
    void writeUnzipFile(string &unzip_str, string &unzipfile_name);//
    void releaseHuffmanTree(unzip_huffman_node *root);//
    void fail();//解压失败的结束函数
};
void unzip_huffman::fail(){
    cout<<"CRICIAL! UNZIP FAILED"<<endl;
    exit(0);
}
//设置压缩文件文件名
void unzip_huffman::setzipfile_name(string _zipfile_name)
{
    zipfile_name = _zipfile_name;
}
//设置解压得到文件名
void unzip_huffman::setunzipfile_name(string _unzipfile_name)
{
    unzipfile_name = _unzipfile_name;
}
//设置解压得到文件名
void unzip_huffman::setkeyfile_name(string _keyfile_name)
{
    keyfile_name = _keyfile_name;
}
//设置解压得到文件名
void unzip_huffman::constructHuffmanMap(string &keyfile_name, string huffman_map[], int &chunk)
{
    ifstream s_keyfile;
    s_keyfile.open(keyfile_name, ios::in | ios::binary);
    if (!s_keyfile.is_open()){
        fail();
        return;
    }
    int num;
    s_keyfile >> chunk;
    //cout << "chunk: " << chunk << endl;
    s_keyfile >> num;
    for (int i = 0; i < num; i++)
    {
        int t;
        string s;
        s_keyfile >> t >> s;
        huffman_map[t] = s;
        //cout << t << " " << s << endl;
    }
}
//将字符串的字节转换为01字符串
void unzip_huffman::readZipstr(string &zipfile_name, string &zip_str, int chunk)
{
    ifstream s_zipfile;
    s_zipfile.open(zipfile_name, ios::in | ios::binary);
    if (!s_zipfile.is_open()){
        fail();
        return;
    }
    while (s_zipfile.peek() != EOF)
    {
        char t_temp[1];
        //s_zipfile >> temp;
        s_zipfile.read(t_temp, 1);
        unsigned char temp=t_temp[0];
        //cout << hex << (int)temp << " ";
        unsigned char mask = 128;
        string t_str;
        for (int i = 0; i < 8; i++)
        {
            t_str += ((temp & mask) != 0 ? '1' : '0');
            mask = mask / 2;
        }
        //cout << t_str << endl;
        zip_str += t_str;
    }
    for (int i = 0; i < chunk; i++)
    {
        zip_str.erase(zip_str.end() - 1);
    }
    //cout << zip_str << endl;
}
//读取文件到字符串
void unzip_huffman::readZipfile(string &zipfile_name, string &keyfile_name, string &zip_str)
{
    constructHuffmanMap(keyfile_name, huffman_map, chunk);
    readZipstr(zipfile_name, zip_str, chunk);
}
//构建huffman树
void unzip_huffman::recreateHuffmanTree(string huffman_map[], unzip_huffman_node *root)
{
    for (int i = 0; i < 256; i++)
    {
        if (huffman_map[i] != "")
        {
            unzip_huffman_node *now = root;
            //cout << dec << i << " : ";
            for (int j = 0; j < huffman_map[i].size() - 1; j++)
            {
                if (huffman_map[i][j] == '0')
                {
                    if (now->right_child == NULL)
                    {
                        unzip_huffman_node *temp = new unzip_huffman_node();
                        now->right_child = temp;
                    }
                    now = now->right_child;
                    //cout << 0;
                }
                if (huffman_map[i][j] == '1')
                {
                    if (now->left_child == NULL)
                    {
                        unzip_huffman_node *temp = new unzip_huffman_node();
                        now->left_child = temp;
                    }
                    now = now->left_child;
                    //cout << 1;
                }
            }
            if (huffman_map[i][huffman_map[i].size() - 1] == '0')
            {
                unzip_huffman_node *leave = new unzip_huffman_node(NULL, NULL, true, i);
                now->right_child = leave;
                //cout << 0;
            }
            if (huffman_map[i][huffman_map[i].size() - 1] == '1')
            {
                unzip_huffman_node *leave = new unzip_huffman_node(NULL, NULL, true, i);
                now->left_child = leave;
                //cout << 1;
            }
            //cout << " end " << endl;
        }
    }
}

void unzip_huffman::unzipFile(string &zip_str, string huffman_map[], string &unzip_str, unzip_huffman_node *root)
{
    unzip_huffman_node *now = root;
    for (auto &c : zip_str)
    {
        if (c == '0')
        {
            now = now->right_child;
            if (now->leave)
            {
                unzip_str += now->c;
                now = root;
            }
        }
        if (c == '1')
        {
            now = now->left_child;
            if (now->leave)
            {
                unzip_str += now->c;
                now = root;
            }
        }
    }
    //cout << unzip_str;
}
//打印huffman树 debug用
void unzip_huffman::printTree(unzip_huffman_node *root)
{
    queue<unzip_huffman_node *> te;
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
            unzip_huffman_node *temp = te.front();
            //cout << dec << now_layel << " : ";
            if (temp->left_child == NULL && temp->right_child == NULL)
            {
                //cout << " " << (int)temp->c << "  leave node  ";
            }
            //cout << endl;
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
    //printTree ok 2020.10.22
}
//将解压得到的字符串传入文件中
void unzip_huffman::writeUnzipFile(string &unzip_str, string &unzipfile_name)
{
    ofstream s_unzipfile;
    s_unzipfile.open(unzipfile_name, ios::out | ios::binary);
    if (!s_unzipfile.is_open())
        return;
    s_unzipfile << unzip_str;
}
//删除huffman树
void unzip_huffman::releaseHuffmanTree(unzip_huffman_node *root)
{
    if (root == NULL)
    {
        return;
    }
    unzip_huffman_node *now = root;
    releaseHuffmanTree(root->right_child);
    releaseHuffmanTree(root->left_child);
    delete now;
}
void unzip_huffman::run()
{
    root = new unzip_huffman_node();
    readZipfile(zipfile_name, keyfile_name, zip_str);//读取文件到字符串
    recreateHuffmanTree(huffman_map, root);//构建huffman树
    unzipFile(zip_str, huffman_map, unzip_str, root);//解压文件存储到字符串中
    //printTree(root);//打印huffman树 debug用
    writeUnzipFile(unzip_str, unzipfile_name);//将解压得到的字符串传入文件中
    releaseHuffmanTree(root);//删除huffman树防止内存泄漏
    cout<<"                 UNZIP OK! "<<endl;
    cout<<"   generate file: \""<<unzipfile_name<<"\""<<endl;
    cout<<"  zipfile length: "<<zip_str.size()/8<<" bytes"<<endl;
    cout<<"unzipfile length: "<<unzip_str.size()<<" bytes"<<endl;
}
int main()
{
    unzip_huffman test1;
    test1.setzipfile_name("zip");//设置需要解压的文件名
    test1.setkeyfile_name("zip.key");//设置需要解压的文件对应的解压信息key文件
    test1.setunzipfile_name("myunzip.bmp");//设置解压后生成文件的文件名
    test1.run();
    return 0;
}