/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * Input    [2,3,1]
 * Output   [1,2,3]
 * Expected [3,1,2]
 */

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j;

		int len = nums.size();
		for (i = len - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				// find in i + 1 to len - 1
				// the smallest nums[j] having nums[i] < nums[j]
				j = len - 1;
				while (nums[i] >= nums[j]) {
					j--;
				}
				assert(i < j);

				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				break;
			}
		}

		i++;
		j = len - 1;
		while (i < j) {
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;

			i++;
			j--;
		}
	}
};

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();

		int bound = 0;
		int currIdx = -1;
		for (int i = len - 1; i > bound; i--) {
			for (int j = i - 1; j >= bound; j--) {
				if (nums[j] < nums[i]) {
					if (j == bound) {
						if (currIdx < 0) {
							currIdx = i;
						}
						else if (nums[i] < nums[currIdx]) {
							currIdx = i;
						}
					}
					else {
						bound = j;
						currIdx = i;
						break;
					}
				}
			}
		}

		if (currIdx > 0) {
			int temp = nums[currIdx];
			nums[currIdx] = nums[bound];
			nums[bound] = temp;

			sort(nums.begin() + bound + 1, nums.end());
		}
		else {
			sort(nums.begin(), nums.end());
		}
	}
};
