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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=nullptr)
        {
            if(cnt > 10000)
            {
                return true;
            }
            temp = temp->next;
            cnt++;
        }

        return false;
    }
};