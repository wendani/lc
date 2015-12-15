/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Given m, n satisfy the following condition:
 * 1 <= m <= n <= length of list.
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {

    struct ListNode *rprev, *rhead;
    
    struct ListNode *prev, *curr, *next;
    int i;

    if (m == n)
        return head;

    // finding the position of rprev and rhead
    if (m == 1) {
        rprev = NULL;
        rhead = head;
    }
    else { // m != 1
        curr = head;
        for (i = 1; i < m - 1; i++)
            curr = curr->next;
        rprev = curr;
        rhead = curr->next;
    }

    // reverse from m to n
    curr = rhead->next;
    prev = rhead;
    for (i = m + 1; i < n + 1; i++) {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    if (rprev)
        rprev->next = prev;
    else
        head = prev;

    rhead->next = curr;

    return head;
}
