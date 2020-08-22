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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp_head = new ListNode;
        temp_head->next = head;
        ListNode *temp_pre = temp_head;
        ListNode *temp_now = temp_head->next;
        ListNode *temp_next = temp_head;
        int count_n = n;
        // 到达第n个
        while(count_n--){
            temp_next = temp_next->next;
        }
        while(temp_next->next){
            temp_next = temp_next->next;
            temp_now = temp_now->next;
            temp_pre = temp_pre->next;
        }
        temp_pre->next = temp_now->next;
        delete temp_now;
        temp_now = NULL;
        auto result = temp_head->next;
        delete temp_head;
        return result;
    }
};