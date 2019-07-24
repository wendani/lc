// distance between two nodes is defined as # of edges between them
int findMaxLen(struct TreeNode *node, int *height)
{
	int maxLen, nMaxLen;
	int lHeight, rHeight;

	if (!node) {
		if (height) {
			*height = -1;
			return -1;
		}
	}

	maxLen = findMaxLen(node->left, &lHeight);
	nMaxLen = findMaxLen(node->right, &rHeight);
	if (nMaxLen > maxLen) {
		maxLen = nMaxLen;
	}

	// calculate the height of the current node
	lHeight++;
	rHeight++;
	if (height) {
		*height = lHeight >= rHeight ? lHeight : rHeight;
	}

	// calculate return value
	nMaxLen = lHeight + rHeight;
	if (nMaxLen > maxLen) {
		maxLen = nMaxLen;
	}

	return maxLen;
}
