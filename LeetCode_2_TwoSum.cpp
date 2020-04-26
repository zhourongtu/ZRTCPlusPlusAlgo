/*
给出两个非空的链表，用来表示两个非负的整数，其中各自位数按照 逆序 方式存储，并且每一个节点只能存储一位数字。
将两个数相加，返回一个新的链表。
*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pre = new ListNode(0);
        ListNode *cur = pre;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int x = l1 == NULL ? 0 : l1->val;
            int y = l2 == NULL ? 0 : l2->val;
            int sum = x + y + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);

            cur = cur->next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry == 1) {
            cur->next = new ListNode(carry);
        }
        return pre->next;
    }
};
