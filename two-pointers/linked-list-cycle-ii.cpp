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
        ListNode* curr = head;
        while (curr) {
            if (curr->val != 10001) {
                curr->val = 10001;
                curr = curr->next;
            } else {
                break;
            }
        }
        return curr;
    }
};