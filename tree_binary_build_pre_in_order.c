/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// recursion
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int rval, i;
	struct TreeNode *root, *ltree, *rtree;

	if ((!preorder) || (!inorder))
		return NULL;

	if ((preorderSize < 1) || (inorderSize < 1))
		return NULL;

	rval = preorder[0];
	for (i = 0; inorder[i] != rval; i++)
		;
	assert(i < inorderSize);

	ltree = buildTree(preorder + 1, i, inorder, i);
	rtree = buildTree(preorder + 1 + i, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);

	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = rval;
	root->left = ltree;
	root->right = rtree;
	return root;
}

// iteration
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
}
