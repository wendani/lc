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
		unordered_set<int> partitionedSum;
		unordered_set<int> toPartitionSum;
		for (int i = 1; i <= sumTarget; i++) {
			toPartitionSum.insert(i);
		}
		partitionedSum.insert(0);

		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] > sumTarget) {
				return false;
			}

			unordered_set<int> canPartitionSum;
			auto it = toPartitionSum.begin();
			while (it != toPartitionSum.end()) {
				if (partitionedSum.count(*it - nums[i])) {
					if (*it == sumTarget) {
						return true;
					}
					canPartitionSum.insert(*it);
					it = toPartitionSum.erase(it);
				}
				else {
					++it;
				}
			}
			partitionedSum.insert(canPartitionSum.begin(), canPartitionSum.end());
		}
		return false;
	}
};

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
		vector<bool> numSum(sumTarget + 1, false);
		int len = nums.size();
		numSum[0] = true;
		for (int i = 0; i < len; i++) {
			if (nums[i] > sumTarget) {
				return false;
			}

			for (int j = sumTarget; j >= nums[i]; j--) {
				if (!numSum[j] && numSum[j - nums[i]]) {
					if (j == sumTarget) {
						return true;
					}
					numSum[j] = true;
				}
			}
		}
		return false;
	}
};
