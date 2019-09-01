static int _maxAncestorDiff(struct TreeNode *node, int *min, int *max)
{
	int maxDiff;
	int cMaxDiff, cmin, cmax;
	int diff;

	if (!node || !min || !max) {
		return -1;
	}

	maxDiff = _maxAncestorDiff(node->left, min, max);

	cMaxDiff = _maxAncestorDiff(node->right, &cmin, &cmax);
	if (cMaxDiff >= 0) {
		if (maxDiff < 0) {
			*min = cmin;
			*max = cmax;
		}
		else {
			// maxDiff >= 0
			if (cmin < *min) {
				*min = cmin;
			}
			if (cmax > *max) {
				*max = cmax;
			}
		}

		if (cMaxDiff > maxDiff) {
			maxDiff = cMaxDiff;
		}
	}

	if (maxDiff < 0) {
		// leaf node;
		*min = node->val;
		*max = node->val;
		return 0;
	}

	// reach here when maxDiff >= 0
	// min contains min of left subtree and right subtree
	// max contains max of left subtree and right subtree
	diff = abs(*min - node->val);
	if (diff > maxDiff) {
		maxDiff = diff;
	}

	diff = abs(*max - node->val);
	if (diff > maxDiff) {
		maxDiff = diff;
	}

	if (node->val < *min) {
		*min = node->val;
	}
	else if (node->val > *max) {
		*max = node->val;
	}

	return maxDiff;
}

int maxAncestorDiff(struct TreeNode* root){
	int min, max;
	return _maxAncestorDiff(root, &min, &max);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/*
 * Input: [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation:
 * We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 */
