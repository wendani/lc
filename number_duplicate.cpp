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
		int len = nums.size();
		int lo = 1;
		int hi = len - 1;

		while (lo <= hi) {
			int mid = (lo + hi) >> 1;

			int loCnt;
			int midCnt;
			count(loCnt, midCnt, nums, lo, mid);
			if (midCnt > 1) {
				return mid;
			}
			else if (loCnt > mid - lo) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return -1;
	}

private:
	void count(int &loCnt, int &midCnt, vector<int> &nums, int lo, int mid)
	{
		int len = nums.size();
		loCnt = 0;
		midCnt = 0;
		for (int i = 0; i < len; i++) {
			if (lo <= nums[i] && nums[i] < mid) {
				loCnt++;
			}
			else if (nums[i] == mid) {
				midCnt++;
			}
		}
	}
};
