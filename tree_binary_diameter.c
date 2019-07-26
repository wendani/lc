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
	int dist, nDist;
	int lHeight, rHeight;

	if (!node) {
		if (height) {
			*height = -1;
		}
		return -1;
	}

	dist = _diameterOfBinaryTree(root->left, &lHeight);
	nDist = _diameterOfBinaryTree(root->right, &rHeight);
	if (nDist > dist) {
		dist = nDist;
	}

	// calculate the height of the current node
	lHeight++;
	rHeight++;
	if (height) {
		*height = lHeight > rHeight ? lHeight : rHeight;
	}

	// calculate return value
	nDist = lHeight + rHeight;
	if (nDist > dist) {
		dist = nDist;
	}
	return dist;
}

int diameterOfBinaryTree(struct TreeNode* root){
	return _diameterOfBinaryTree(root, NULL);
}
