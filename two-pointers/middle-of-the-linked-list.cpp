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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        int tempcnt = cnt;
        cnt = 0;
        ListNode* temp1 = head;
        if (tempcnt % 2 != 0) {
            int mid = tempcnt / 2;
            while (cnt != mid && temp1) {
                cnt++;
                temp1 = temp1->next;
            }
            return temp1;
        } else {
            int mid = (tempcnt / 2);
            while (cnt != mid && temp1) {
                cnt++;
                temp1 = temp1->next;
            }

            return temp1;
        }
    }
};