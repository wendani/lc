/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev, *curr, *nxt;

    if (!head) return NULL;

    prev = head;
    curr = prev->next;
    while (curr) {
        if (prev->val == curr->val) {
            nxt = curr->next;
            prev->next = nxt;
            free(curr);
            curr = nxt;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
