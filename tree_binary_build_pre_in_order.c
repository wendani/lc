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
	int i, j, lo, up, nup;
	struct TreeNode *root, *add_pnt, *p, *op;

	if ((!preorder) || (!inorder))
		return NULL;

	if ((preorderSize < 1) || (inorderSize < 1))
		return NULL;

	// initialization
	for (i = 0; preorder[i] != inorder[0]; i++)
		;
	assert(i < preorderSize);
	up = i;
	lo = i + 1;

	root = NULL;
	add_pnt = NULL;

	// core
	i = 0;
	while (i < inorderSize) {
		if (lo > 0 && preorder[lo - 1] == inorder[i]) {
			lo--;

			p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
			p->val = preorder[lo];
			p->left = root;
			p->right = NULL;

			// update root and add point
			add_pnt = p;
			root = p;
			i++;
		} else {
			// construct right subtree and connect
			for (nup = up + 1; preorder[nup] != inorder[i]; nup++)
				;
			assert(nup < preorderSize);

			op = NULL;
			for (j = nup; j > up; j--) {
				p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
				p->val = preorder[j];
				p->left = op;
				p->right = NULL;

				op = p;
			}
			add_pnt->right = op;

			// update add point and upper bound
			add_pnt = op;
			i += (nup - up);
			up = nup;
		}
	}

	return root;
}
