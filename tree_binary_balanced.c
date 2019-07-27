/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool __isBalanced(struct TreeNode *root, int *depth)
{
	int ldepth, rdepth;
	bool lbalanced, rbalanced;

	if (!root) {
		if (depth)
			*depth = 0;
		return true;
	}

	lbalanced = __isBalanced(root->left, &ldepth);
	rbalanced = __isBalanced(root->right, &rdepth);

	// calculate the height of the current node
	if (depth)
		*depth = (ldepth >= rdepth) ? (ldepth + 1) : (rdepth + 1);
	// if (depth) {
	// 	if (ldepth >= rdepth) {
	// 		*depth = ldepth + 1;
	// 	}
	// 	else {
	// 		// ldepth < rdepth
	// 		*depth = rdepth + 1;
	// 	}
	// }

	// calculate return value
	if (!lbalanced || !rbalanced) {
		return false;
	}
	// reach here when both children are balanced
	return (abs(ldepth - rdepth) > 1) ? false : true;

	// if (lbalanced && rbalanced) {
	// 	if (ldepth - rdepth > 1 || ldepth - rdepth < -1) {
	// 		return false;
	// 	}
	// 	return true;
	// }
	// return false;
}

bool isBalanced(struct TreeNode* root) {
	bool balanced;

	balanced = __isBalanced(root, NULL);
	return balanced;
}
