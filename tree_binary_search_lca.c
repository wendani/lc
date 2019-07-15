struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode *lca;

	if (!root) {
		return NULL;
	}

	if (p->val < root->val && root->val < q->val) {
		return root;
	}

	if (q->val < root->val && root->val < p->val) {
		return root;
	}

	if (p->val == root->val || q->val == root->val) {
		return root;
	}

	if (p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	}

	// reach here when (root->val < p->val && root->val < q->val)
	return lowestCommonAncestor(root->right, p, q);
}
