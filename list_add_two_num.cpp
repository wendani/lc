/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int num1 = getNum(l1);
		int num2 = getNum(l2);

		int num = num1 + num2;
		stack<int> digiStk;
		while (num) {
			digiStk.push(num % 10);
			num /= 10;
		}

		ListNode *curr = NULL;
		while (!digiStk.empty()) {
			int &digit = digiStk.top();

			ListNode *node = new ListNode(digit);
			node->next = curr;
			curr = node;

			digiStk.pop();
		}
		return curr;
	}

private:
	int getNum(ListNode *node)
	{
		if (!node) {
			return 0;
		}

		int num = getNum(node->next);
		return num * 10 + node->val;
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
}
