static bool _verifyPreorder(int *preorder, int startIdx, int endIdxExcl)
{
	int i, j;

	// no element case
	if (startIdx == endIdxExcl) {
		return true;
	}

	// one element case
	if (startIdx + 1 == endIdxExcl) {
		return true;
	}

	// more than one element case
	for (i = startIdx + 1; i < endIdxExcl && preorder[i] < preorder[startIdx]; i++) {
		;
	}

	for (j = i; j < endIdxExcl; j++) {
		if (preorder[j] < preorder[startIdx]) {
			return false;
		}
	}

	return _verifyPreorder(preorder, startIdx + 1, i) && _verifyPreorder(preorder, i, endIdxExcl);
}

bool verifyPreorder(int* preorder, int preorderSize) {
	if (!preorder) {
		return false;
	}

	if (preorderSize < 1) {
		return false;
	}

	return _verifyPreorder(preorder, 0, preorderSize);
}


/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 *
 * https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/
 *
 * algorithms
 * Medium (44.49%)
 * Total Accepted:    40.7K
 * Total Submissions: 91.5K
 * Testcase Example:  '[5,2,6,1,3]'
 *
 * Given an array of numbers, verify whether it is the correct preorder
 * traversal sequence of a binary search tree.
 *
 * You may assume each number in the sequence is unique.
 *
 * Consider the following binary search tree:
 *
 *
 * ⁠    5
 * ⁠   / \
 * ⁠  2   6
 * ⁠ / \
 * ⁠1   3
 *
 * Example 1:
 *
 *
 * Input: [5,2,6,1,3]
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: [5,2,1,3,6]
 * Output: true
 *
 * Follow up:
 * Could you do it using only constant space complexity?
 *
 */
