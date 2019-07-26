/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
	int i;
	int rval;
	struct TreeNode *node, *ltree, *rtree;

	if (!pre || !post) {
		return NULL;
	}
	if (preSize != postSize) {
		return NULL;
	}

	if (preSize < 1) {
		return NULL;
	}

	node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val = pre[0];

	if (preSize == 1) {
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	// reach here when preSize >= 2
	rval = post[postSize - 2];
	for (i = preSize - 1; i > 0 && pre[i] != rval; i--)
		;

	ltree = constructFromPrePost(pre + 1, i - 1, post, i - 1);
	rtree = constructFromPrePost(pre + i, preSize - i, post + i - 1, postSize - i);

	node->left = ltree;
	node->right = rtree;
	return node;
}
