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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp_head = new ListNode;
        ListNode *now = temp_head;
        int min_index;
        int min_data;
        int flag_finish;
        while(true){
            min_index = -1;
            min_data = INT_MAX;
            for(int i=0; i<lists.size(); i++){
                if(lists[i] != NULL){
                    if(lists[i]->val < min_data){
                        min_data = lists[i]->val;
                        min_index = i;
                    }
                }
            }
            if(min_index==-1){
                break;
            }    
            now->next = lists[min_index];
            now = now->next;
            lists[min_index] = lists[min_index]->next;
            now->next = NULL;
        }
        auto result = temp_head->next;
        delete temp_head;
        return result;
    }
};

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};