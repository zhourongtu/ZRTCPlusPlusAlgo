#include <iostream>
#include <cmath>
#include <vector>
#include <list>

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

class Solution{
public:
    // 1.使用parent
    Node* lowest_common_parent(Node *a, Node *b){
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
};
int main()
{
    Node *a = new Node; a->_value = 100;
    Node *a_l = new Node;
    Node *a_r = new Node;
    a->_left = a_l; a->_right = a_r;
    a_l->_parent = a; a_r->_parent = a;
    Solution s;
    cout << (*s.lowest_common_parent(a_l, a_r))._value;
    
    return 0;
}
