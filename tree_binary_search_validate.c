/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
	if (!root)
		return true;

	if ((root->left) && (root->left->val >= root->val))
		return false;

	if ((root->right) && (root->right->val <= root->val))
		return false;

	if (isValidBST(root->left))
		return isValidBST(root->right);
	else
		return false;
}
