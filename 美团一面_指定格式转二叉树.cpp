#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

/*
将特定格式的字符串，转换成二叉树
*/
struct Node{
    string data;
    struct Node * _left = NULL;
    struct Node * _right = NULL;
};

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    Node* ConvertToTree(ifstream &f){
        //这里再造一个data
        vector<string> data;
        string s;
        while(getline(f, s)){
            data.push_back(s);
        }
        return buildTree(data, 0, 0);
    }

    //用index 指示
    Node* buildTree(vector<string> &data, int root_pos, int index){
        string str = data[root_pos].substr(index);
        Node *result = new Node;
        result->data = str;
        int root_l_pos, root_r_pos;
        root_l_pos = root_pos + 1;
        int count = 0;
        for(int i=root_l_pos; i<data.size(); i++){
            if(data[i].size() > index+1 && data[i][index] == '\t' && data[i][index+1] != '\t'){
                count++;
                root_r_pos = i;
            }
        }
        if(count == 0){
            return result;
        }else{
            result->_left = buildTree(data, root_l_pos, index+1);
            if(count == 2){
                result->_right = buildTree(data, root_r_pos, index+1);
            }
        }
        return result;
    }

};
void BFS(Node *root);
int main()
{
    ifstream f;
    f.open("ConvertToBinaryTree.txt");
    Node *b;
    Solution a;
    b = a.ConvertToTree(f);

    //BFS
    BFS(b);
    return 0;
}
//添加换行机制
void BFS(Node *root){
    queue<Node *> q;
    Node *nlast;
    Node *last = root;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data << '\t';
        if(temp->_left){
            q.push(temp->_left);
            nlast = temp->_left;
        }
        if(temp->_right){
            q.push(temp->_right);
            nlast = temp->_right;
        }
        if(temp == last){
            cout << endl;
            last = nlast;
        }
    }
    return;
}
