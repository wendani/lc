/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd, *even;
    struct ListNode *otail, *etail;
    int i;

    if (!head) return NULL;
    
    odd   = head;
    otail = head;
    even  = odd->next;
    etail = even;
    if (!even) return odd;

    i = 0;
    head = even->next;
    while (head) {
        ++i;
        if (i == 1) {
            otail->next = head;
            otail = head;
        }
        else {
            // i == 2
            etail->next = head;
            etail = head;
            i = 0;
        }
        head = head->next;
    }
    otail->next = even;
    etail->next = NULL;
    return odd;
}
