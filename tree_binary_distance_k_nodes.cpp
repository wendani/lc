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
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> nodes;
		int distToTarget;
		findTarget(nodes, distToTarget, root, target, K);
		return nodes;
	}

private:
	void findNodes(vector<int> &nodes, TreeNode *node, const int dist)
	{
		if (!node || dist < 0) {
			return;
		}

		if (dist == 0) {
			nodes.push_back(node->val);
			return;
		}

		// reach here when dist > 0
		findNodes(nodes, node->left, dist - 1);
		findNodes(nodes, node->right, dist - 1);
	}

	int findTarget(vector<int> &nodes, int &distToTarget, TreeNode *node, TreeNode *target, const int &K)
	{
		if (!node || !target) {
			return -1;
		}

		if (node == target) {
			distToTarget = 0;
			findNodes(nodes, node, K);
			return 0;
		}

		if (!findTarget(nodes, distToTarget, node->left, target, K)) {
			distToTarget++;
			if (distToTarget < K) {
				findNodes(nodes, node->right, K - distToTarget - 1);
			}
			else if (distToTarget == K) {
				nodes.push_back(node->val);
			}
			return 0;
		}

		if (!findTarget(nodes, distToTarget, node->right, target, K)) {
			distToTarget++;
			if (distToTarget < K) {
				findNodes(nodes, node->left, K - distToTarget - 1);
			}
			else if (distToTarget == K) {
				nodes.push_back(node->val);
			}
			return 0;
		}

		return -1;
	}
};
