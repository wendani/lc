/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int sum){
	if (!root) {
		return false;
	}

	if (!root->left && !root->right && root->value == sum) {
		return true;
	}

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (38.69%)
 * Total Accepted:    352K
 * Total Submissions: 909.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 *
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 */
