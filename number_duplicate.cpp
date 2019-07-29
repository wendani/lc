/*
 * Example 1:
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 *
 * Example 2:
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 */


class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		// idx is understood as address
		int slowIdx = nums[0];
		int fastIdx = nums[slowIdx];

		while (slowIdx != fastIdx) {
			slowIdx = nums[slowIdx];
			fastIdx = nums[nums[fastIdx]];
		}

		// reach here when slowIdx == fastIdx
		slowIdx = 0;
		while (slowIdx != fastIdx) {
			slowIdx = nums[slowIdx];
			fastIdx = nums[fastIdx];
		}

		return slowIdx;
	}
};

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	}
};
