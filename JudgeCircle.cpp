#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct ListNode{
    int data;
    ListNode *next = NULL;
};
/*判断链表是否成环*/
class Solution{
public:
    bool JudgeCircle(ListNode *list){
        if(list == NULL || list->next == NULL)return false;
        if(list->next == list)return true;
        ListNode *p_slow, *p_fast;
        p_slow = p_fast = list;
        while(p_fast){
            //快的走两步
            p_fast = p_fast->next;
            if(p_fast == NULL || p_fast->next == NULL)return false;
            p_fast = p_fast->next;
            //慢的走一步
            p_slow = p_slow->next;
            if(p_fast == p_slow){
                return true;
            }
        }
        return false;
    }
};
int main()
{
    ListNode *p = new ListNode; p->data = 1;
    p->next = new ListNode; p->next->data = 2;
    p->next->next = new ListNode;
    Solution a;
    cout << "成环结果：" << a.JudgeCircle(p) << endl;
    return 0;
}
