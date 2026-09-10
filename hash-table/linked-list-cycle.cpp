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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->val == 100001) {
                return true;
            } else {
                temp->val = 100001;
                temp = temp->next;
            }
        }

        return false;
    }
};