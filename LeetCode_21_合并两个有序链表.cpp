/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)return NULL;
        ListNode *temp_head = new ListNode;
        ListNode *now = temp_head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                now->next = new ListNode(l1->val);
                now = now->next;
                l1 = l1->next;
            }else if(l1->val > l2->val){
                now->next = new ListNode(l2->val);
                now = now->next;
                l2 = l2->next;
            }
        }
        while(l1 != NULL){
            now->next = new ListNode(l1->val);
            now = now->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            now->next = new ListNode(l2->val);
            now = now->next;
            l2 = l2->next;
        }
        auto result = temp_head->next;
        delete temp_head;
        return result;
    }
};