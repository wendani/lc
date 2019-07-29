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
	bool isCompleteTree(TreeNode* root) {
		if (!root) {
			return true;
		}

		int size = 2;
		vector<bool> nodeExist(size, true);

		queue<TreeNode *> nodeQ;

		int idx = 1;
		nodeQ.push(root);
		while (!nodeQ.empty()) {
			if (!nodeExist[idx]) {
				return false;
			}

			if (idx << 1 == size) {
				size <<= 1;
				nodeExist.resize(size, false);
			}

			TreeNode *node = nodeQ.front();
			if (node->left) {
				nodeExist[2 * idx] = true;
				nodeQ.push(node->left);
			}
			if (node->right) {
				nodeExist[2 * idx + 1] = true;
				nodeQ.push(node->right);
			}
			nodeQ.pop();

			idx++;
		}
		return true;
	}
};
