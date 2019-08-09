/*
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 */


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (const auto &num : nums) {
			sum += num;
		}

		if (sum & 0x1) {
			return false;
		}

		int sumTarget = sum >> 1;
		if (nums[0] == sumTarget) {
			return true;
		}

		vector<vector<bool>> numSum;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			numSum.emplace_back(sumTarget + 1, false);
			numSum[i][0] = true;
		}
		numSum[0][nums[0]] = true;
		for (int i = 1; i < len; i++) {
			for (int j = 1; j < nums[i]; j++) {
				numSum[i][j] = nums[i - 1][j];
			}
			for (int j = nums[i]; j <= sumTarget; j++) {
				if (numSum[i - 1][j - nums[i]] || numSum[i - 1][j]) {
					if (j == sumTarget) {
						return true;
					}
					numSum[i][j] = true;
				}
			}
		}
	}
};
