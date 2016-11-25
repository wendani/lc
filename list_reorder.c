/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
	int i;
	struct ListNode *mid, *prev, *curr, *next;

	if (!head)
		return;

	curr = head->next;
	if (!curr)
		return;

	// reach here, the list contains at least two elements
	// find the second half of the list
	// when the # of elements are even, mid points to the tail of the first half of the list
	mid = head;
	i = 0;
	while (curr) {
		++i;

		if (i == 2) {
			mid = mid->next;
			i = 0;
		}

		curr = curr->next;
	}
	curr = mid->next;
	mid->next = NULL;

	// reorder the second half
	prev = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	curr = prev;

	// interleave the two lists
	prev = head;
	next = prev->next;
	while (curr && next) {
		prev->next = curr;
		prev = curr;
		curr = curr->next;

		prev->next = next;
		prev = next;
		next = next->next;
	}
	if (curr)
		prev->next = curr;
}
