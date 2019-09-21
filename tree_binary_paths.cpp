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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		_binaryTreePaths(paths, root);
		return paths;
	}
private:
	void _binaryTreePaths(vector<string> &paths, TreeNode *node)
	{
		if (!node) {
			return;
		}

		if (!node->left && !node->right) {
			paths.push_back(to_string(node->val));
			return;
		}

		_binaryTreePaths(paths, node->left);

		vector<string> rPaths;
		_binaryTreePaths(rPaths, node->right);
		paths.insert(paths.end(), rPaths.begin(), rPaths.end());

		for (auto &path : paths) {
			path.insert(0, to_string(node->val) + "->");
		}
	}
};


/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (47.27%)
 * Total Accepted:    247.8K
 * Total Submissions: 523.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 *
 */
