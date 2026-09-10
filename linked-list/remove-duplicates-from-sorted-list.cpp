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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* temp = head;
        set<int> v;
        while(temp != NULL)
        {
            v.insert(temp->val);
            temp = temp->next;
        }

        ListNode* start = new ListNode();
        ListNode* tail = start;

        for(auto it : v)
        {
            tail->next = new ListNode(it);
            tail = tail->next;
        }
        return start->next;
    }
};