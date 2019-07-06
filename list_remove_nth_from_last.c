/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *curr, *nprev, *ncurr;
    int i;

    curr = head;
    for (i = 1; i < n; i++) {
        if (!curr) return head;
        curr = curr->next;
    }
    ncurr = head;
    nprev = NULL;

    curr = curr->next;
    while (curr) {
        nprev = ncurr;
        ncurr = ncurr->next;

        curr = curr->next;
    }

    if (!nprev)
        head = head->next;
    else
        nprev->next = ncurr->next;

    free(ncurr);
    return head;
}

