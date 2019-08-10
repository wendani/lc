/*
 * Example 1:
 *
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 */


class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		for (const auto &num : nums) {
			sum += num;
		}

		if (sum % k) {
			return false;
		}

		int sumTarget = sum / k;
		vector<bool> numSum(sum + 1, false);
		numSum[0] = true;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] > sumTarget) {
				return false;
			}

			for (int j = sum; j >= nums[i]; j--) {
				if (!numSum[j] && numSum[j - nums[i]]) {
					numSum[j] = true;
				}
			}
		}

		for (int i = sumTarget; i <= sum; i += sumTarget) {
			if (!numSum[i]) {
				return false;
			}
		}
		return true;
	}
};
