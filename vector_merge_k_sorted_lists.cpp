/*
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode *, vector<ListNode *>, comp> listNodeMinPriQ;
		for (const auto &list : lists) {
			if (list) {
				listNodeMinPriQ.push(list);
			}
		}

		ListNode *head = NULL;
		ListNode *tail;
		while (!listNodeMinPriQ.empty()) {
			ListNode *node = listNodeMinPriQ.top();
			listNodeMinPriQ.pop();

			if (!head) {
				head = node;
				tail = head;
			}
			else {
				tail->next = node;
				tail = node;
			}

			node = node->next;
			if (node) {
				listNodeMinPriQ.push(node);
			}
		}
		if (head) {
			tail->next = NULL;
		}

		return head;
	}
private:
	struct comp {
		bool operator()(const ListNode *a, const ListNode *b) {
			if (a->val >= b->val) {
				return true;
			}
			return false;
		}
	};
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode *, vector<ListNode *>, comp> listNodeMinPriQ;
		stack<ListNode *> listNodeStk;

		for (const auto &list : lists) {
			if (list) {
				listNodeMinPriQ.push(list);
			}
		}

		while (!listNodeMinPriQ.empty()) {
			ListNode *node = listNodeMinPriQ.top();
			listNodeMinPriQ.pop();

			listNodeStk.push(node);

			node = node->next;
			if (node) {
				listNodeMinPriQ.push(node);
			}
		}

		ListNode *prev = NULL;
		while (!listNodeStk.empty()) {
			ListNode *curr = listNodeStk.top();
			listNodeStk.pop();

			curr->next = prev;
			prev = curr;
		}
		return prev;
	}
private:
	struct comp {
		bool operator()(const ListNode *a, const ListNode *b) {
			if (a->val >= b->val) {
				return true;
			}
			return false;
		}
	};
};
