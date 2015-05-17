/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode *reverseList(struct ListNode *head) {

    struct ListNode *nhd;

    if (!head)
        return head;

    if (!head->next)
        return head;

    nhd = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return nhd;
}
