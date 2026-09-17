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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
            return nullptr;
        int cnt = 0;

        ListNode* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        int nr = cnt - n;
        ListNode* temp2 = head;

        int newcnt = 1;
        while (temp2 != nullptr) {
            cout << temp2->val << endl;
            if (newcnt == nr) {
                if (temp2->next->next == nullptr) {
                    temp2->next = nullptr;
                    break;
                } else {
                    temp2->next = temp2->next->next;
                    break;
                }
            }
            newcnt++;
            temp2 = temp2->next;
        }

        return head;
    }
};