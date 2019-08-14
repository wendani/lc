/*
 * Example:
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> rightSideViewNodes;
		if (!root) {
			return rightSideViewNodes;
		}

		queue<TreeNode *> q[2];
		queue<TreeNode *> *curr = &q[0];
		queue<TreeNode *> *next = &q[1];

		curr->push(root);
		while (!curr->empty()) {
			TreeNode *node = NULL;
			while (!curr->empty()) {
				node = curr->front();
				if (node->left) {
					next->push(node->left);
				}
				if (node->right) {
					next->push(node->right);
				}
				curr->pop();
			}
			rightSideViewNodes.push_back(node->val);

			queue<TreeNode *> *temp = curr;
			curr = next;
			next = temp;
		}

		return rightSideViewNodes;
	}
};
