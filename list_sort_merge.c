/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/** 
 * when the # of elements is even,
 * this finds the head of the second half 
 */

static struct ListNode *midElement(struct ListNode *head)
{
    struct ListNode *curr, *mid;
    int i;

    curr = head;
    mid  = head;
    i = 0;
    while (curr) {
        i++;
        if (i == 2) {
            mid = mid->next;
            i = 0;
        }
        curr = curr->next;
    }

    return mid;
}

/** 
 * when the # of elements is even,
 * this finds the tail of the first half 
 */
static struct ListNode *midElement_2(struct ListNode *head)
{
    struct ListNode *curr, *mid;
    int i;

    if (!head) return NULL; //

    curr = head->next;
    if (!curr) return head; //

    mid = head;
    i = 0;
    while (curr) {
        i++;
        if (i == 2) {
            mid = mid->next;
            i = 0;
        }
        curr = curr->next;
    }

    return mid;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *fst_half, *fst_tail, *scd_half;
    struct ListNode *tail;
    
    if (!head) return NULL;
    if (!head->next) return head;

    // halve the list
    fst_tail = midElement_2(head);
    scd_half = fst_tail->next;
    fst_tail->next = NULL;

    // obtain the sorted halves
    fst_half = sortList(head);
    scd_half = sortList(scd_half);

    // merge two halves into one
    if (fst_half->val < scd_half->val) {
        head = fst_half;
        fst_half = fst_half->next;
    }
    else {
        head = scd_half;
        scd_half = scd_half->next;
    }
    tail = head;
    
    while (fst_half && scd_half) {
        if (fst_half->val < scd_half->val) {
            tail->next = fst_half;
            fst_half = fst_half->next;
        }
        else {
            tail->next = scd_half;
            scd_half = scd_half->next;
        }
        tail = tail->next;
    }
    if (fst_half)
        tail->next = fst_half;
    else
        tail->next = scd_half;

    return head;
}
