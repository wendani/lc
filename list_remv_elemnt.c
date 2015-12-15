/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode *curr = head;
    struct ListNode *prev = NULL;

    while (curr) {
        if (curr->val == val) {
            // remove element

            if (!prev) {
                // head of list
                curr = curr->next;
                free(head);
                head = curr;
            }
            else {
                prev->next = curr->next;
                free(curr);
                curr = prev-next;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
