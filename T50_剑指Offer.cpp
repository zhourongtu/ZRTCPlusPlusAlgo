#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <queue>

using namespace std;

/*
 * 树中两个结点的最低公共祖先
*/

// 1.二叉树
struct Node{
    int _value;
    Node *_left = NULL, *_right = NULL;
    Node *_parent = NULL;
};

struct NormalNode{
    int _value;
    std::vector<NormalNode*> children;
};

class Solution{
public:
    // 0.二叉树
    Node* lowest_common_parent_0(Node *a, Node *b){
        // 1.找根结点
        Node *root = a;
        while(root->_parent != NULL){
            root = root->_parent;
        }
        int big, small;
        big = a->_value > b->_value ? a->_value : b->_value;
        small = a->_value > b->_value ? b->_value : a->_value;
        // 2.根据该根结点，层序遍历，查找，介于a和b之间的值。
            //临时写一个层序遍历的函数？或者直接在这里使用。
        queue<Node*> q;
        q.push(root);
        Node *result = NULL;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp->_value >= small && temp->_value <= big){
                // 3.根据特性，该值为最低公共结点
                result = temp;
                break;
            }else if(temp->_value > big){
                if(temp->_left) q.push(temp->_left);
            }else if(temp->_value < small){
                if(temp->_right) q.push(temp->_right);
            }// 经过修改后，不判断有没有，根据大小进行优化
        }
        return result;
    }
    // 1.指向parent的树 + 双向链表
    Node* lowest_common_parent_1(Node *a, Node *b){
        list<Node*> l1, l2;
        while(a->_parent){
            l1.push_front(a->_parent);
            a = a->_parent;
        }
        while(b->_parent){
            l2.push_front(b->_parent);
            b = b->_parent;
        }
        // 寻找最早的一个公共结点
        auto temp_l1 = l1.begin();
        auto temp_l2 = l2.begin();
        while(*temp_l1 == *temp_l2 && temp_l1 != l1.end() && temp_l2 != l2.end()){
            ++temp_l1;
            ++temp_l2;
        }
        return *(--temp_l1);
    }
    // 2.普通的树，没有二叉树性质，且可能存在多个子树
    // 此时应该给定一个根结点，否则就没用。思路是DFS，并且记录
    //   方法1：写一个函数，判断是否在某个点是否在不同子树上。
    //          子节点不包含两个值，且自己包含两个值
    //   方法2：使用DFS，搜索相应的路径，并保存下来。
    //         再使用比较。
    //   时间复杂度：O(n)在树中搜索一个值。
    //   空间复杂度：深度，大概是O(logn)
    NormalNode* lowest_common_parent_2(){
        //类似于链表。略
    }
};
int main()
{
    Node *a = new Node; a->_value = 100;
    Node *a_l = new Node; a_l->_value = 50;
    Node *a_r = new Node; a_r->_value = 1001;
    a->_left = a_l; a->_right = a_r;
    a_l->_parent = a; a_r->_parent = a;
    Solution s;
    cout << (*s.lowest_common_parent_0(a_l, a_r))._value << endl;
    cout << (*s.lowest_common_parent_1(a_l, a_r))._value << endl;
    
    return 0;
}
