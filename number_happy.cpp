/*
 * Example:
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */


class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> nums;
		while (n != 1) {
			nums.insert(n);

			// calculate the next n
			int sum = 0;
			while (n) {
				int m = n % 10;
				sum += (m * m);
				n /= 10;
			}

			if (nums.count(sum)) {
				return false;
			}
			n = sum;
		}
		return true;
	}
};
