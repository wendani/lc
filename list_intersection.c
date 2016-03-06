/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static int nodeCount(struct ListNode *head)
{
    int cnt = 0;

    while (head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

/**
 * return tail and element count
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

/**
 * return new head and element count
 */
static struct ListNode *listReverse(struct ListNode *head, int *cnt)
{
    struct ListNode *prev, *curr, *nxt;
    
    prev = NULL;
    curr = head;
    *cnt = 0;
    while (curr) {
        ++(*cnt);

        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }
    return prev;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA, *tailB;
    int a, b, c;
    int ac_sum, bc_sum, ab_sum;
    struct ListNode *intersect;

    if (!headA || !headB) return NULL;

    tailA = listTraverse(headA, &ac_cum);
    tailB = listReverse(headB, &bc_sum);
    if (tailA != tailB) {
        // retain list B's orginial structure
        listReverse(tailB, &bc_sum);
        return NULL;
    }
    
    --ac_sum;
    --bc_sum;
    ab_sum = nodeCount(headA) - 1;
    c = (ac_sum + bc_sum - ab_sum) / 2;

    prev = NULL;
    curr = tailB;
    cnt = -1;
    while (curr) {
        ++cnt;
        if (cnt == c) 
            intersect = curr;

        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }
    return intersect;
}
