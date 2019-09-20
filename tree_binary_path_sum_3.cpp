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
	int pathSum(TreeNode* root, int sum) {
		vector<int> sumStartFromRoot;
		int sumCount = 0;
		_pathSum(sumStartFromRoot, sumCount, root, sum);
		return sumCount;
	}
private:
	void _pathSum(vector<int> &sumStartFromNode, int &count, TreeNode *node, const int sumTarget)
	{
		if (!node) {
			return;
		}

		_pathSum(sumStartFromNode, count, node->left, sumTarget);

		vector<int> rSumStartFromNode;
		int rCount = 0;
		_pathSum(rSumStartFromNode, rCount, node->right, sumTarget);
		sumStartFromNode.insert(sumStartFromNode.end(), rSumStartFromNode.begin(), rSumStartFromNode.end());
		count += rCount;

		for (auto &sum : sumStartFromNode) {
			sum += node->val;
			if (sum == sumTarget) {
				count++;
			}
		}

		sumStartFromNode.push_back(node->val);
		if (node->val == sumTarget) {
			count++;
		}
	}
};


/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (43.71%)
 * Total Accepted:    123.8K
 * Total Submissions: 283.2K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 *
 *
 */
