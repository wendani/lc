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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> preTrav;
		_preorderTraversal(preTrav, root);
		return preTrav;
	}
private:
	void _preorderTraversal(vector<int> &preTrav, TreeNode *node) {
		if (!node) {
			return;
		}

		preTrav.push_back(node->val);
		_preorderTraversal(preTrav, node->left);
		_preorderTraversal(preTrav, node->right);
	}
};
