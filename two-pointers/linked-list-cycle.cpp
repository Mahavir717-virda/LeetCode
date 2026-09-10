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
        vector<int> v;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            v.push_back(temp->val);
        }

        int cnt = 0;
        ListNode *temp1 = head;
        while(temp1 != nullptr)
        {
            if(cnt > v.size())
                return false;
            cnt++;
            temp1 = temp1->next;
        }

        return false;
    }
};