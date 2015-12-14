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
    struct ListNode *rprev, *rnext;
    struct ListNode *rhead, *rtail;
    
    struct ListNode *prev, *curr, *next;
    int i;

    if (m == n)
        return head;

    // finding the position of rprev, rhead, rtail, and rnext
    rprev = NULL;
    curr = head;
    for (i = 1; i < n; i++) {
        if (i == m - 1)
            rprev = curr;
        if (i == m)
            rhead = curr;

        curr = curr->next;
    }
    rtail = curr;
    rnext = curr->next;


    if (rprev)
        rprev->next = rtail;
    else
        head = rtail;

    // reverse from m to n
    curr = rhead->next;
    prev = rhead;
    while (curr != rnext) {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    rhead->next = rnext;

    return head;
}
