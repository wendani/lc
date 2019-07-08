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




struct ListNode *_remove(struct ListNode *node, int *pos, int n)
{
	if (!node) {
		*pos = 0;
		return NULL;
	}

	int npos;
	struct ListNode *next = _remove(node->next, &npos, n);
	*pos = npos + 1;
	if (*pos ==  n) {
		free(node);
		return next;
	}
	else {
		node->next = next;
		return node;
	}
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int hpos;
	return _remove(head, &hpos, n);
}
