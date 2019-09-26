class Solution {
public:
	int pathSum(vector<int>& nums) {
		vector<int> vTree(32, -1);
		for (auto num : nums) {
			int uDigit = num % 10;

			num /= 10;
			int tDigit = num % 10;
			int hDigit = num / 10;
			assert(hDigit < 10);

			int idx = pow(2, hDigit - 1) + (tDigit - 1);
			vTree[idx] = uDigit;
		}

		int sum = 0;
		int pathCnt = 0;
		_pathSum(sum, pathCnt, vTree, 1);
		return sum;
	}
private:
	void _pathSum(int &sum, int &pathCnt, vector<int> &vTree, int nodeIdx)
	{
		if (vTree[nodeIdx] < 0) {
			return;
		}

		if (vTree[nodeIdx * 2] < 0 && vTree[nodeIdx * 2 + 1] < 0) {
			sum += vTree[nodeIdx];
			pathCnt++;
			return;
		}

		_pathSum(sum, pathCnt, vTree, nodeIdx * 2);

		int rPathCnt = 0;
		_pathSum(sum, rPathCnt, vTree, nodeIdx * 2 + 1);
		pathCnt += rPathCnt;

		sum += pathCnt * vTree[nodeIdx];
	}
};

/*
 * @lc app=leetcode id=666 lang=cpp
 *
 * [666] Path Sum IV
 *
 * https://leetcode.com/problems/path-sum-iv/description/
 *
 * algorithms
 * Medium (53.35%)
 * Total Accepted:    9.4K
 * Total Submissions: 17.6K
 * Testcase Example:  '[113,215,221]'
 *
 * If the depth of a tree is smaller than 5, then this tree can be represented
 * by a list of three-digits integers.
 *
 * For each integer in this list:
 *
 *
 * The hundreds digit represents the depth D of this node, 1 <= D <= 4.
 * The tens digit represents the position P of this node in the level it
 * belongs to, 1 <= P <= 8. The position is the same as that in a full binary
 * tree.
 * The units digit represents the value V of this node, 0 <= V <= 9.
 *
 *
 *
 *
 * Given a list of ascending three-digits integers representing a binary tree
 * with the depth smaller than 5, you need to return the sum of all paths from
 * the root towards the leaves.
 *
 * Example 1:
 *
 *
 * Input: [113, 215, 221]
 * Output: 12
 * Explanation:
 * The tree that the list represents is:
 * ⁠   3
 * ⁠  / \
 * ⁠ 5   1
 *
 * The path sum is (3 + 5) + (3 + 1) = 12.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [113, 221]
 * Output: 4
 * Explanation:
 * The tree that the list represents is:
 * ⁠   3
 * ⁠    \
 * ⁠     1
 *
 * The path sum is (3 + 1) = 4.
 *
 *
 *
 *
 */
