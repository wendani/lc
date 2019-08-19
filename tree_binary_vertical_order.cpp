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
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> verticals;
		if (!root) {
			return verticals;
		}

		int leftMost = 0;
		int rightMost = 0;
		findEnds(leftMost, rightMost, root, 0);
		verticals.resize(rightMost - leftMost + 1);

		queue<pair<TreeNode *, int>> nodeQ;
		nodeQ.emplace(root, 0 - leftMost);
		while (!nodeQ.empty()) {
			auto &p = nodeQ.front();
			verticals[p.second].push_back(p.first->val);

			if (p.first->left) {
				nodeQ.emplace(p.first->left, p.second - 1);
			}

			if (p.first->right) {
				nodeQ.emplace(p.first->right, p.second + 1);
			}

			nodeQ.pop();
		}
		return verticals;
	}
private:
	void findEnds(int &leftMost, int &rightMost, TreeNode *node, int nodeVerticalIdx)
	{
		if (!node) {
			return;
		}

		if (nodeVerticalIdx < leftMost) {
			leftMost = nodeVerticalIdx;
		}

		if (nodeVerticalIdx > rightMost) {
			rightMost = nodeVerticalIdx;
		}

		findEnds(leftMost, rightMost, node->left, nodeVerticalIdx - 1);
		findEnds(leftMost, rightMost, node->right, nodeVerticalIdx + 1);
	}
};

/*
 * Examples 1:
 *
 * Input: [3,9,20,null,null,15,7]
 *
 *    3
 *   /\
 *  /  \
 *  9  20
 *     /\
 *    /  \
 *   15   7
 *
 * Output:
 *
 * [
 *   [9],
 *   [3,15],
 *   [20],
 *   [7]
 * ]
 *
 * Examples 2:
 *
 * Input: [3,9,8,4,0,1,7]
 *
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 *
 * Output:
 *
 * [
 *   [4],
 *   [9],
 *   [3,0,1],
 *   [8],
 *   [7]
 * ]
 *
 * Examples 3:
 *
 * Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
 *
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 *     /\
 *    /  \
 *    5   2
 *
 * Output:
 *
 * [
 *   [4],
 *   [9,5],
 *   [3,0,1],
 *   [8,2],
 *   [7]
 * ]
 */
