/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * return list tail and # of elements
 */
static struct ListNode *listTraverse(struct ListNode *head, int *cnt)
{
    struct ListNode *prev = NULL;

    *cnt = 0;
    while (head) {
        ++(*cnt);

        prev = head;
        head = head->next;
    }
    return prev;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA, *tailB;
    int ac_sum, bc_sum, ab_diff;
    int i;

    if (!headA || !headB) return NULL;

    tailA = listTraverse(headA, &ac_sum);
    tailB = listTraverse(headB, &bc_sum);
    if (tailA != tailB)
        return NULL;

    ab_diff = ac_sum - bc_sum;
    if (ab_diff > 0) {
        // move headA by ab_diff steps
        for (i = 0; i < ab_diff; ++i)
            headA = headA->next;
    }
    else if (ab_diff < 0) {
        // move headB by ab_diff steps
        ab_diff = -ab_diff;
        for (i = 0; i < ab_diff; ++i)
            headB = headB->next;
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
