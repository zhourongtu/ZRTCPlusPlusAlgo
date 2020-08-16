#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteRange(ListNode *start, ListNode *end){
        if(start == NULL)return start;
        ListNode *returnResult = end->next;
        while(start != end){
            ListNode *temp = start->next;
            delete start;
            start = temp;
        }
        delete end;
        return returnResult;
    }
    
    ListNode* deleteDuplication(ListNode*& pHead)
    {
        if(pHead == NULL)return pHead;
        ListNode *judgeFirst = pHead;
        // 找出第一个是否重复
        while(judgeFirst->next != NULL && judgeFirst->next->val == pHead->val){
            judgeFirst = judgeFirst->next;
        }
        // 此时judgeFirst指向最后一个与pHead值相同的，或者最后一个结点
		if(judgeFirst != pHead && judgeFirst->val == pHead->val){
			// 代表可以全部删掉
			pHead = deleteRange(pHead, judgeFirst);
			pHead = deleteDuplication(pHead);
		}
        // 开始拼接
        if(pHead){
			pHead->next = deleteDuplication(pHead->next);
		}
        return pHead;
    }
};



class Solution {
public:
    ListNode* deleteRange(ListNode *start, ListNode *end){
        if(start == NULL)return start;
        ListNode *returnResult = end->next;
        while(start != end){
            ListNode *temp = start->next;
            delete start;
            start = temp;
        }
        delete end;
        return returnResult;
    }
    
    ListNode* deleteDuplication(ListNode*& pHead)
    {
        ListNode *vHead = new ListNode(-1);
        vHead->next = pHead;
        ListNode *pre = vHead, *cur = pHead;
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                cur = cur->next;
                while(cur->next && cur->val == cur->next->val){
                    cur = cur->next;
                }
                ListNode *temp = cur->next;
                pre->next = deleteRange(pre->next, cur);
                cur = temp;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        auto result = vHead->next;
        delete vHead;
        return result;
    }
};


int main()
{
	ListNode *a = new ListNode(1);
	a->next = new ListNode(1);
	// a->next->next = new ListNode(3);
	// a->next->next->next = new ListNode(3);
	// a->next->next->next->next = new ListNode(4);
	// a->next->next->next->next->next = new ListNode(4);
	// a->next->next->next->next->next->next = new ListNode(5);
	Solution s;
	s.deleteDuplication(a);
	if(a == NULL)cout << "zhourongtu";
	// while(a){	
	// 	cout << "\t" << a->val;
	// 	a = a->next;
	// }
	return 0;
}