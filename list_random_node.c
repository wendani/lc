/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
	int tot;
	struct ListNode *head;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
	int cnt = 0;
	stuct ListNode *curr = head;
	
	Solution *obj = (Solution *)malloc(sizeof(Solution));
	if (!obj)
		return NULL;

	while (!curr) {
		cnt++;
		curr = curr->next;
	}

	obj->tot  = cnt;
	obj->head = head;
	return obj;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
	int i, idx;
	struct ListNode *curr;

	// need to validate input, but the following may not work
	if (!obj)
		return -1;
	
	idx = rand() % obj->cnt;
	curr = obj->head;
	for (i = 0; i < idx; i++)
		curr = curr->next;

	return curr->val;
}

void solutionFree(Solution* obj) {
	free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */  
