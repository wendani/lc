/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {

    struct ListNode *curr, *nxt;
    struct ListNode *newhd;

    if (!head)
        return false;

    curr = head->next;
    newhd = head;
    newhd->next = NULL;

    while (curr) {
        nxt = curr->next;
        curr->next = newhd;

        newhd = curr;
        curr = nxt;
    }

    if (newhd == head)
        return true;

    return false;
}
