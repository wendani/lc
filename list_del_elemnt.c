/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {

    struct ListNode *prev, *curr;

    if (!node)
        return;

    prev = node;
    curr = node->next;
    while (curr) {
        prev->val = curr->val;
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);
}
