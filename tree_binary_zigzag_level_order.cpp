/*
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> zigzag;
		if (!root) {
			return zigzag;
		}

		stack<TreeNode *> stk[2];
		stack<TreeNode *> *curr = &stk[0];
		stack<TreeNode *> *next = &stk[1];

		int isLeftToRight = 1;
		curr->push(root);
		while (!curr->empty()) {
			zigzag.emplace_back();
			while (!curr->empty()) {
				TreeNode *node = curr->top();

				zigzag.back().push_back(node->val);
				if (isLeftToRight) {
					next->push(node->left);
					next->push(node->right);
				}
				else {
					next->push(node->right);
					next->push(node->left);
				}
				curr->pop();
			}

			stack<TreeNode *> *temp = curr;
			curr = next;
			next = temp;

			isLeftToRight = (isLeftToRight + 1) & 0x1;
		}
		return zigzag;
	}
};
