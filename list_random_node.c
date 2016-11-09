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
	int cnt;
	struct ListNode *curr;
	
	Solution *obj = (Solution *)malloc(sizeof(Solution));
	if (!obj)
		return NULL;

	curr = head;
	cnt  = 0;
	while (curr) {
		cnt++;
		curr = curr->next;
	}

	obj->tot  = cnt;
	obj->head = head;
	return obj;
}

/** Returns a random node's value. */
/* Caller must make sure that obj is not NULL */
int solutionGetRandom(Solution* obj) {
	int i, idx;
	struct ListNode *curr;

	// need to validate input, but the following may not work
//	if (!obj)
//		return -1;
	
	srand(time(NULL));
	idx = rand() % obj->tot;
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
