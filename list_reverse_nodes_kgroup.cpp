/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		stack<ListNode *> nodeStk;

		ListNode **prevTail = &head;
		while (*prevTail) {
			// find a segment of k nodes
			ListNode *curr = *prevTail;
			int i = 0;
			while (curr && i < k) {
				nodeStk.push(curr);

				curr = curr->next;
				i++;
			}
			if (i < k) {
				return head;
			}

			// reach here when we have a complete segment
			ListNode *prev = NULL;
			while (!nodeStk.empty()) {
				if (!prev) {
					prev = nodeStk.top();
					*prevTail = prev;
				}
				else {
					prev->next = nodeStk.top();
					prev = prev->next;
				}

				nodeStk.pop();
			}

			// stitch with the unexplored
			prev->next = curr;
			prevTail = &prev->next;
		}
		return head;
	}
};

/*
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */
