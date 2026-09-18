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
    ListNode* deleteMiddle(ListNode* head) {

          if (!head->next)
            return nullptr;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt / 2;
        ListNode* prev = head;
        for(int i = 0;i < mid - 1; i++)
        {
            prev = prev->next;
        }

        ListNode* l = prev->next;
        prev->next = prev->next->next;
        delete l;
        
        return head;
    }
};