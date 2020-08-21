#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

// 1.先序遍历。 打印顶，然后右左。

// 2.中序遍历，左压栈，弹出节点（压到右边去）

// 3.后序遍历。弹出结点，压入左，右。（弹出放在s2）
class node{
public:
    node(int a):m_value(a),m_left(NULL),m_right(NULL){}
public:
    int m_value;
    node* m_left;
    node* m_right;
};

class Solution{
public:
    vector<int> pre_order(node *root){
        // 前序遍历的核心-->root开始,再左边,再右边
        vector<int> result;
        stack<node*> my_stack;
        my_stack.push(root);
        while(!my_stack.empty()){
            node* temp = my_stack.top();
            my_stack.pop();
            result.push_back(temp->m_value);
            if(temp->m_right){
                my_stack.push(temp->m_right);
            }
            if(temp->m_left){
                my_stack.push(temp->m_left);
            }
        }
        return result;
    }
    
    vector<int> in_order(node *root){
        vector<int> result;
        stack<node*> my_stack;
        // 左，中，右-->向左边压栈
        node *temp = root;
        while(!my_stack.empty() || temp != NULL){
            while(temp){
                my_stack.push(temp);
                temp = temp->m_left;
            }
            temp = my_stack.top();
            my_stack.pop();
            result.push_back(temp->m_value);
            temp = temp->m_right;
        }
        return result;
    }

    vector<int> post_order(node *root){
        // 
        vector<int> result;
        stack<node*> my_stack;
        // 左 右 后
        auto temp = root;
        while(!my_stack.empty() || temp){ // temp处理第一个的情况
            if(temp){
                result.push_back(temp->m_value);
            }else{
                temp = my_stack.top();
                my_stack.pop();
                result.push_back(temp->m_value);
            }
            if(temp->m_left){
                my_stack.push(temp->m_left);
            }
            if(temp->m_right){
                my_stack.push(temp->m_right);
            }
            temp = NULL;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    node *a = new node(1);
    a->m_left = new node(2);
    a->m_right = new node(3);
    Solution s;
    auto result_pre = s.pre_order(a);
    for_each(result_pre.begin(), result_pre.end(), [](int a){cout << a << "\t";});
    auto result_in = s.in_order(a);
    for_each(result_in.begin(), result_in.end(), [](int a){cout << a << "\t";});
    auto result_post = s.post_order(a);
    for_each(result_post.begin(), result_post.end(), [](int a){cout << a << "\t";});
    // auto result_in = s.in_order(a);
    return 0;
}
