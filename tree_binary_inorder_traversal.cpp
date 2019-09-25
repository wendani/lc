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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode *> stk;
		while (root) {
			stk.push(root);
			root = root->left;
		}

		vector<int> inOrderVals;
		while (!stk.empty()) {
			TreeNode *node = stk.top();
			inOrderVals.push_back(node->val);
			stk.pop();

			node = node->right;
			while (node) {
				stk.push(node);
				node = node->left;
			}
		}
		return inOrderVals;
	}
};


/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.50%)
 * Total Accepted:    532.5K
 * Total Submissions: 908.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
