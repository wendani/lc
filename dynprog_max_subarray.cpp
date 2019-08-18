/*
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();

		int max = nums[len - 1];
		int maxFromNextIdx = nums[len - 1];
		for (int i = len - 2; i >= 0; i--) {
			int maxFromCurrIdx = nums[i] + maxFromNextIdx;
			if (maxFromCurrIdx < nums[i]) {
				maxFromCurrIdx = nums[i];
			}

			if (maxFromCurrIdx > max) {
				max = maxFromCurrIdx;
			}

			maxFromNextIdx = maxFromCurrIdx;
		}
		return max;
	}
};
