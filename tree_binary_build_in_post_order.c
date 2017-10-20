/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	int rval, i;
	struct TreeNode *root, *lsubtree, *rsubtree;

	if (!inorder || !postorder)
		return NULL;

	if ((inorderSize < 1) || (postorderSize < 1))
		return NULL;

	rval = postorder[postorderSize - 1];
	for (i = 0; inorder[i] != rval; i++)
		;
	assert(i < inorderSize);

	lsubtree = buildTree(inorder, i, postorder, i);
	rsubtree = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);

	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = rval;
	root->left = lsubtree;
	root->right = rsubtree;
	return root;
}
