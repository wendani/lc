struct TreeNode *_lca(struct TreeNode *node, struct TreeNode *p, struct TreeNode *q, bool *pAncestor, bool *qAncestor) {
	struct TreeNode *lca;
	bool lpAncestor, lqAncestor, rpAncestor, rqAncestor;

	if (!node) {
		*pAncestor = false;
		*qAncestor = false;
		return NULL;
	}

	lca = _lca(node->left, p, q, &lpAncestor, &lqAncestor);
	if (lca) {
		return lca;
	}

	lca = _lca(node->right, p, q, &rpAncestor, &rqAncestor);
	if (lca) {
		return lca;
	}

	// reach here when we have not found the lca node
	*pAncestor = lpAncestor || rpAncestor || node == p;
	*qAncestor = lqAncestor || rqAncestor || node == q;
	if (*pAncestor && *qAncestor) {
		return node;
	}
	return NULL;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	bool pAncestor, qAncestor;

	return _lca(root, p, q, &pAncestor, &qAncestor);
}
