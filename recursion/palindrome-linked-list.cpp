class Solution {
public:
    ListNode* reverse(ListNode* newhead) {
        ListNode* temp = newhead;
        ListNode* prev = nullptr;
        ListNode* tail = nullptr;
        while (temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newhead;

        while (second != nullptr) {
            if (first->val != second->val) {
                reverse(newhead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
