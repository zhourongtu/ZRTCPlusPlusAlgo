/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)return head;
        if(head == NULL || head->next == NULL)return head;
        ListNode my_head, *tail = &my_head;
        my_head.next = head;
        int count = 0;
        ListNode *pre, *cur, *next;
        pre = tail; cur = pre->next;    
        
        int len = 0;
        {
            auto temp = head;
            while(temp){
                len++;
                temp = temp->next;
            }
        }
        for(int i=0; i<len/k; i++){
        // 实现k翻转
            int count = 0;
            next = cur->next; // next的初始化由cur决定
            // 翻转k-1个指向
            while(count < k-1){
                count++;
                auto temp = next->next;
                next->next = cur;
                cur = next;
                next = temp;
            }
            // 修改指针-->此时cur在最后结点，next在外面
            auto temp_tail = pre->next; //保存该翻转的最后一个尾结点
            temp_tail->next = next; // 尾结点做为节点该做的事情
            pre->next = cur; // 新的头结点由cur构成
            // 为下一次做准备（我的概念是只准备pre和cur）
            pre = temp_tail; 
            cur = pre->next;
        }
        return my_head.next;
    }
};