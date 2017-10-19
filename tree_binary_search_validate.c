/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool __isValidBST(struct TreeNode* root, int *lower_bound_for_left_child, int *upper_bound_for_right_child) {
	if (!root)
		return true;

	if (root->left) {
		if (root->left->val >= root->val)
			return false;

		if ((lower_bound_for_left_child) && (root->left->val <= *lower_bound_for_left_child)
			return false;
	}

	if (root->right) {
		if (root->right->val <= root->val)
			return false;

		if ((upper_bound_for_right_child) && (root->right->val >= *upper_bound_for_right_child))
			return false;
	}

	if (__isValidBST(root->left, lower_bound_for_left_child, &root->val))
		return __isValidBST(root->right, &root->val, upper_bound_for_right_child);
	else
		return false;
}

bool isValidBST(struct TreeNode* root) {
	return __isValidBST(root, NULL, NULL);
}
