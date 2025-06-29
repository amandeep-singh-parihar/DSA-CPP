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
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        // ListNode *fast, *slow, *entry;
        // fast = head;
        // slow = head;
        // entry = head;
        // while (fast->next != NULL && fast->next->next != NULL) {
        //     fast = fast->next->next;
        //     slow = slow->next;
        //     if (fast == slow) {
        //         while (slow != entry) {
        //             slow = slow->next;
        //             entry = entry->next;
        //         }
        //         return entry;
        //     }
        // }

        unordered_set<ListNode*> vis;
        ListNode* temp1 = head;
        while(temp1!=NULL){
            if(vis.find(temp1)!=vis.end()){
                return temp1;
            }
            vis.insert(temp1);
            temp1=temp1->next;
        }

        return NULL;
    }
};