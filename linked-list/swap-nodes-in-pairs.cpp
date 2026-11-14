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
    // ListNode* swap(ListNode* head, ListNode* nextnode) {
    //     if (nextnode == nullptr or head->next == nullptr) {
    //         return head;
    //     }

    //     ListNode* temp = head;
    //     head = nextnode;
    //     head->next =nextnode->next;
    //     nextnode = temp;
    //     nextnode->next = temp->next;

    //     return swap(nextnode->next, nextnode->next->next);
    // }
    ListNode* swapPairs(ListNode* head) {

        if (!head)
            return nullptr;

        if (head->next == nullptr)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next!=nullptr and prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            //swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // update the prev for the next pairs
            prev = first;
            
        }

        return dummy.next;
    }
};