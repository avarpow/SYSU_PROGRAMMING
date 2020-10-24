#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>

using namespace std;
const int ZIP_LENGTH = 8;
struct huffman_node
{
    char c;
    int count;
    huffman_node *left_child,*right_child,*parent;
    bool friend operator<(huffman_node a, huffman_node b)
    {
        return a.count < b.count;
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
void createheap(const vector<int> &huffman_count, priority_queue<huffman_node> &heap_huffman)
{
    for (int i = 0; i < 256; i++)
    {
        if (huffman_count[i] != 0)
        {
            huffman_node t;
            t.c = i;
            t.count = huffman_count[i];
            t.left_child=t.right_child=t.parent=NULL;
            heap_huffman.push(t);
        }
    }
}
huffman_node * createtree(priority_queue<huffman_node> &heap_huffman)
{
    while(heap_huffman.size()>1){
        huffman_node *tnode=new huffman_node();
        huffman_node *firstnode=new huffman_node();
        huffman_node *secnode=new huffman_node();
        *firstnode=heap_huffman.top();
        heap_huffman.pop();
        *secnode=heap_huffman.top();

    huffman_node *ret=new huffman_node();
    *ret=heap_huffman.top();
    return ret;
}
void printtree(huffman_node *root){
    queue<huffman_node> te;
    int now_layel=0;
    te.push( root);
    while(!te.empty()){
        int k=te.size();
        now_layel++;
        for(int i=0;i<k;i++){
            
        }
    }
        int k=te.size();
        now_layel++;
        for(int i=0;i<k;i++){
            
        }
    }
        int k=te.size();
        now_layel++;
        for(int i=0;i<k;i++){
            
        }
    }

}
// void zipfile();
// void writefile();
int main()
{
    string inputfile_name = "nozip";
    string str_input;
    vector<int> huffman_count;
    priority_queue<huffman_node> heap_huffman;
    huffman_node *root;
    openfile(inputfile_name, str_input);
    count_huffman_node(huffman_count, str_input);
    createheap(huffman_count, heap_huffman);
    root=createtree(heap_huffman);

    printtree(root);
    // genzipfile();
    // genkeyfile();
    // writefile();
    return 0;
}
