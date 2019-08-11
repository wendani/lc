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
		sort(nums.begin(), nums.end());
		return _canPartition(nums, 0, sumTarget);
	}
private:
	// Can get sum starting from startIdx
	bool _canPartition(const vector<int> &sortedNums, int startIdx, int sum)
	{
		int len = sortedNums.size();
		if (startIdx > len) {
			return false;
		}

		if (startIdx == len) {
			if (sum == 0) {
				return true;
			}
			return false;
		}

		if (sortedNums[startIdx] == sum) {
			return true;
		}

		if (sortedNums[startIdx] > sum) {
			return false;
		}

		int nextIdx = startIdx + 1;
		sum -= sortedNums[startIdx];
		for (; nextIdx < len && sortedNums[nextIdx]  == sortedNums[nextIdx - 1]; nextIdx++) {
			sum -= sortedNums[startIdx];
		}
		for (int i = 0; i <= nextIdx - startIdx; i++) {
			if (_canPartition(sortedNums, nextIdx, sum)) {
				return true;
			}
			sum += sortedNums[startIdx];
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
		sort(nums.begin(), nums.end());
		return _canPartition(nums, 0, sumTarget);
	}
private:
	// Can get sum starting from startIdx
	bool _canPartition(const vector<int> &sortedNums, int startIdx, int sum)
	{
		int len = sortedNums.size();
		if (startIdx >= len) {
			return false;
		}

		if (sortedNums[startIdx] == sum) {
			return true;
		}

		if (sortedNums[startIdx] > sum) {
			return false;
		}

		if (_canPartition(sortedNums, startIdx + 1, sum - sortedNums[startIdx])
			|| _canPartition(sortedNums, startIdx + 1, sum)) {
			return true;
		}
		return false;
	}
};

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (const auto num : nums) {
			sum += num;
		}

		if (sum & 0x1) {
			return false;
		}

		int sumTarget = sum >> 1;
		unordered_set<int> partitionedSum = {0};

		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] > sumTarget) {
				return false;
			}

			unordered_set<int> canPartitionSum;
			for (const auto &pSum : partitionedSum) {
				int cSum = pSum + nums[i];
				if (cSum == sumTarget) {
					return true;
				}
				canPartitionSum.insert(cSum);
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
		vector<vector<bool>> numSum;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] == sumTarget) {
				return true;
			}
			else if (nums[i] > sumTarget) {
				return false;
			}
			numSum.emplace_back(sumTarget + 1, false);
			numSum[i][0] = true;
		}

		numSum[0][nums[0]] = true;
		for (int i = 1; i < len; i++) {
			for (int j = 1; j < nums[i]; j++) {
				if (numSum[i - 1][j]) {
					numSum[i][j] = true;
				}
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
		return false;
	}
};
