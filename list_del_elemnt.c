/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {

    struct ListNode *pprev, *prev, *curr;

    if (!node)
        return;

    pprev = NULL;
    prev  = node;
    curr  = node->next;
    while (curr) {
        prev->val = curr->val;

        pprev = prev;
        prev  = curr;
        curr  = curr->next;
    }

    if (pprev) {
        pprev->next = NULL;
        free(prev);
    }
}
