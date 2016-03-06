/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static inline struct ListNode *lastElement(struct ListNode *head) 
{
    if (!head) return NULL;
    
    while (head->next)
        head = head->next;

    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *se_head, *l_head, *pvt;
    struct ListNode *curr, *prv, *nxt;
    struct ListNode *pvt_tail;

    if (!head) return NULL;
    if (!head->next) return head;

    se_head = NULL;
    l_head  = NULL;
    pvt      = head;
    pvt_tail = head;
    curr  = head->next;
    while (curr) {
        nxt = curr->next;

        if (curr->val > pvt->val) {
            curr->next = l_head;
            l_head = curr;
        }
        else if (curr->val < pvt->val) {
            curr->next = se_head;
            se_head = curr;
        }
        else {
            curr->next = pvt;
            pvt = curr;
        }

        curr = nxt;
    }

    se_head = sortList(se_head);
    l_head  = sortList(l_head);
    
    prv = lastElement(se_head);
    if (!prv)
        se_head   = pvt;
    else
        prv->next = pvt;

    pvt_tail->next = l_head;

    
    return se_head;
}
