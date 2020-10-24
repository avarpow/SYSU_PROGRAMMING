#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <map>

using namespace std;
string huffman_map[256];
struct unzip_huffman_node
{
    char c;
    bool leave;
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
void construct_huffman_map(string &keyfile_name, string huffman_map[], int &chunk)
{
    ifstream s_keyfile;
    s_keyfile.open(keyfile_name, ios::in | ios::binary);
    if (!s_keyfile.is_open())
        return;
    int num;
    s_keyfile >> chunk;
    cout << "chunk: " << chunk << endl;
    s_keyfile >> num;
    for (int i = 0; i < num; i++)
    {
        int t;
        string s;
        s_keyfile >> t >> s;
        huffman_map[t] = s;
        cout << t << " " << s << endl;
    }
}
void read_zipstr(string &zipfile_name, string &zip_str, int chunk)
{
    ifstream s_zipfile;
    s_zipfile.open(zipfile_name, ios::in | ios::binary);
    if (!s_zipfile.is_open())
        return;
    while (s_zipfile.peek() != EOF)
    {
        unsigned char temp;
        s_zipfile >> temp;
        cout << hex << (int)temp << " ";
        unsigned char mask = 128;
        string t_str;
        for (int i = 0; i < 8; i++)
        {
            t_str += ((temp & mask) != 0 ? '1' : '0');
            mask = mask / 2;
        }
        cout << t_str << endl;
        zip_str += t_str;
    }
    for (int i = 0; i < chunk; i++)
    {
        zip_str.erase(zip_str.end() - 1);
    }
    cout << zip_str << endl;
}
void read_zipfile(string &zipfile_name, string &keyfile_name, string &zip_str)
{
    int chunk;
    construct_huffman_map(keyfile_name, huffman_map, chunk);
    read_zipstr(zipfile_name, zip_str, chunk);
}
void recreate_huffman_tree(string huffman_map[], unzip_huffman_node *root)
{
    for (int i = 0; i < 256; i++)
    {
        if (huffman_map[i] != "")
        {
            unzip_huffman_node *now = root;
            cout << dec << i << " : ";
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
                    cout << 0;
                }
                if (huffman_map[i][j] == '1')
                {
                    if (now->left_child == NULL)
                    {
                        unzip_huffman_node *temp = new unzip_huffman_node();
                        now->left_child = temp;
                    }
                    now = now->left_child;
                    cout << 1;
                }
            }
            if (huffman_map[i][huffman_map[i].size() - 1] == '0')
            {
                unzip_huffman_node *leave = new unzip_huffman_node(NULL, NULL, true, i);
                now->right_child = leave;
                cout << 0;
            }
            if (huffman_map[i][huffman_map[i].size() - 1] == '1')
            {
                unzip_huffman_node *leave = new unzip_huffman_node(NULL, NULL, true, i);
                now->left_child = leave;
                cout << 1;
            }
            cout << " end " << endl;
        }
    }
}
void unzip_file(string &zip_str, string huffman_map[], string &unzip_str, unzip_huffman_node *root)
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
    cout << unzip_str;
}
void printtree(unzip_huffman_node *root)
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
            cout << dec << now_layel << " : ";
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
void write_unzip_file(string &unzip_str, string &unzipfile_name)
{
    ofstream s_unzipfile;
    s_unzipfile.open(unzipfile_name, ios::out | ios::binary);
    if (!s_unzipfile.is_open())
        return;
    s_unzipfile << unzip_str;
}
void release_huffman_tree(unzip_huffman_node *root)
{
    if(root==NULL ){
        return;
    }
    unzip_huffman_node *now=root;
    release_huffman_tree(root->right_child);
    release_huffman_tree(root->left_child);
    delete now;
}
int main()
{
    string zipfile_name = "nozip_zip";
    string unzipfile_name = "unzip_file";
    string keyfile_name = "nozip_key";
    string zip_str;
    string unzip_str;
    unzip_huffman_node *root = new unzip_huffman_node();
    read_zipfile(zipfile_name, keyfile_name, zip_str);
    recreate_huffman_tree(huffman_map, root);
    unzip_file(zip_str, huffman_map, unzip_str, root);
    printtree(root);
    write_unzip_file(unzip_str, unzipfile_name);
    release_huffman_tree(root);
    return 0;
}