/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


static bool __isSubtree(struct TreeNode *s, struct TreeNode *t)
{
	if ((!s && t) || (s && !t)) {
		return false;
	}

	if (!s && !t) {
		return true;
	}

	// reach here when s && t
	if (s->val != t->val) {
		return false;
	}

	return __isSubtree(s->left, t->left) && __isSubtree(s->right, t->right);
}

static int height(struct TreeNode *node)
{
	int lHeight, rHeight;

	if (!node) {
		return -1;
	}

	lHeight = height(node->left);
	rHeight = height(node->right);

	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

static bool _isSubtree(int *sHeight, struct TreeNode *s, struct TreeNode *t, const int tHeight)
{
	int lHeight, rHeight;
	bool lIsSubtree, rIsSubtree;

	assert(sHeight);
	if (!s) {
		*sHeight = -1;
		return false;
	}

	lIsSubtree = _isSubtree(&lHeight, s->left, t, tHeight);
	if (lIsSubtree) {
		return lIsSubtree;
	}
	rIsSubtree = _isSubtree(&rHeight, s->right, t, tHeight);
	if (rIsSubtree) {
		return rIsSubtree;
	}

	// reach here when !lIsSubtree && !rIsSubtree
	*sHeight = lHeight >= rHeight ? lHeight + 1 : rHeight + 1;

	if (*sHeight == tHeight) {
		return __isSubtree(s, t);
	}
	return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	int sHeight;
	int tHeight = height(t);
	return _isSubtree(&sHeight, s, t, tHeight);
}


/*
 * Example 1:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *
 * Given tree t:
 *
 *    4
 *   / \
 *  1   2
 *
 * Return true, because t has the same structure and node values with a subtree of s.
 *
 * Example 2:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 *
 * Given tree t:
 *
 *    4
 *   / \
 *  1   2
 *
 * Return false.
 */
