class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int len = nums.size();
		assert(len > 2);
		int closest = nums[0] + nums[1] + nums[2] - target;
		for (int i = 0; i < len - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			int t = target - nums[i];
			int j = i + 1;
			int k = len - 1;
			while (j < k) {
				int twoSum = nums[j] + nums[k];
				if (twoSum == t) {
					return target;
				}
				else if (twoSum < t) {
					if (t - twoSum < abs(closest)) {
						closest = twoSum - t;
					}
					j++;
				}
				else {
					// twoSum > t
					if (twoSum - t < abs(closest)) {
						closest = twoSum - t;
					}
					k--;
				}
			}
		}
		return target + closest;
	}
};


/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Total Accepted:    383.3K
 * Total Submissions: 837.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
