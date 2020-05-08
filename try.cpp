#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

/*
将特定格式的字符串，转换成二叉树
1.从上往下的顺序，本质是一棵二叉树的中序遍历。
2.通过父子树能够判断左右子树的大小。

结论：需要进行修改和调整
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
        return buildTree(data, 0, 0, data.size());
    }

    //用index 指示
    //代码出了Bug。左子树和右子树没有划分一个范围。
    //数据，根节点位置，此时index开始为根节点的数据。子树的index为\t
    Node* buildTree(vector<string> &data, int root_pos, int index, int length){
        if(length <= 0) return NULL;
        string str = data[root_pos].substr(index);
        Node *result = new Node;
        result->data = str;
        int root_l_pos, root_r_pos;
        int count = 0;
        root_l_pos = root_pos + 1;
        for(int i=root_pos + 1; i < root_pos + length; i++){
            if(data[i].size() > index+1 && data[i][index] == '\t' && data[i][index+1] != '\t'){
                count++;
                root_r_pos = i;
            }
        }
        if(count == 0){
            return result;
        }else{
            if(count == 1){
                int left_length = length - 1;
                result->_left = buildTree(data, root_l_pos, index+1, left_length);
            }
            if(count == 2){
                int left_length = root_r_pos - root_pos - 1;
                result->_left = buildTree(data, root_l_pos, index+1, left_length);
                int right_length = length - 1 - left_length;
                result->_right = buildTree(data, root_r_pos, index+1, right_length);
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
