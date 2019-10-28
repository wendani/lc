/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _findSecondMinimumValue(int *target, struct TreeNode *node, int min)
{
	if (!node) {
		return;
	}

	if (node->val == min) {
		_findSecondMinimumValue(target, node->left, min);
		_findSecondMinimumValue(target, node->right, min);
	}
	else {
		assert(node->val > min);
		if (*target < 0) {
			*target = node->val;
		}
		else if (node->val < *target) {
			*target = node->val;
		}
	}
}

int findSecondMinimumValue(struct TreeNode* root){
	int secMin = -1;

	if (!root) {
		return -1;
	}

	_findSecondMinimumValue(&secMin, root, root->val);
	return secMin;
}


/*
 * @lc app=leetcode id=671 lang=c
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (43.13%)
 * Total Accepted:    58.4K
 * Total Submissions: 135.4K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. More formally, the property root.val
 * = min(root.left.val, root.right.val) always holds.
 *
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 *
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 *
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
 *
 *
 *
 *
 */
