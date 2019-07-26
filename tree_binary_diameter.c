/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int _diameterOfBinaryTree(struct TreeNode *node, int *height)
{
	int diam, nDiam;
	int lHeight, rHeight;

	if (!node) {
		if (height) {
			*height = -1;
		}
		return -1;
	}

	diam = _diameterOfBinaryTree(node->left, &lHeight);
	nDiam = _diameterOfBinaryTree(node->right, &rHeight);
	if (nDiam > diam) {
		diam = nDiam;
	}

	// calculate the height of the current node
	lHeight++;
	rHeight++;
	if (height) {
		*height = lHeight > rHeight ? lHeight : rHeight;
	}

	// calculate return value
	nDiam = lHeight + rHeight;
	if (nDiam > diam) {
		diam = nDiam;
	}
	return diam;
}

int diameterOfBinaryTree(struct TreeNode* root){
	return _diameterOfBinaryTree(root, NULL);
}
