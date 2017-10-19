/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode *reverseList(struct ListNode *head) {

    struct ListNode *nhd;
    struct ListNode *curr;

    if (!head)
        return head;

    nhd = head->next;
    head->next = NULL;
    while (nhd) {
        curr = nhd;
        nhd = curr->next;

        curr->next = head;
        head = curr;
    }

    return head;
}


struct ListNode *reverseList(struct ListNode *head) {
	struct ListNode *prev, *curr, *nxt;

	curr = head;
	prev = NULL;
	while (curr) {
		nxt = curr->next;
		currr->next = prev;

		prev = curr;
		curr = nxt;
	}

	return prev;
}
