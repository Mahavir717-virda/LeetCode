class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (curr->val == val) {
                // Link the previous node to the next node, bypassing 'curr'
                prev->next = curr->next;
                
                ListNode* dummy = curr;
                curr = curr->next;
                delete dummy; 
            } else {
                // Move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};
