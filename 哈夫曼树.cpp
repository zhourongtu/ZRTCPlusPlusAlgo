#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <functional>
using namespace std;

/*请在这里输入这个程序的功能或者作用*/

class node{
public:
    node(int val):val(val), left(NULL), right(NULL){}
public:
    bool operator<(const node &rhs){
        return this->val < rhs.val;
    }
    bool operator>(const node &rhs){
        return this->val >= rhs.val;
    }
public:
    int val;
    node *left;
    node *right;
};

class Compare_Node_Pointer: public binary_function<node*, node*, bool>
{
public:
    bool operator()(node* &a, node* &b) const
    {
        return a->val > b->val;
    }

};
class Solution{
public:
    node *getHuffman(vector<int> &nums){
        priority_queue<node*, vector<node*>, Compare_Node_Pointer> my_queue;
        for(int i=0; i<nums.size(); i++){
            my_queue.push(new node(nums[i]));    
        }
        // 进行处理了
        while(my_queue.size() > 1){
            auto a = my_queue.top();
            my_queue.pop();
            auto b = my_queue.top();
            my_queue.pop();
            auto temp = new node(a->val+b->val);
            temp->left = a;
            temp->right = b;
            my_queue.push(temp);
        }
        auto result = my_queue.top();
        my_queue.pop();
        return result;
    }
    void in_order(node *root){
        if(root==NULL)return;
        queue<node*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()){
            auto temp = my_queue.top();
            my_queue.pop();
            //
        }
    }
};
int main()
{
    vector<int> nums = {2, 6, 1, 3, 2};
    Solution s;
    auto root = s.getHuffman(nums);
    s.in_order(root);
    return 0;
}
