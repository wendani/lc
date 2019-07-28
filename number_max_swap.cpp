/*
 * Example 1:
 *
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 *
 * Example 2:
 *
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 */

class Solution {
public:
	int maximumSwap(int num) {
		if (num < 10) {
			return num;
		}

		while (num) {
			digits.push_back(num % 10);
			num /= 10;
		}

		int len = digits.size();
		vector<int> indices;
		for (int i = 0; i < len; i++) {
			indices.push_back(i);
		}
		sort(indices.begin(), indices.end(), &Solution::comp);

		for (int i = len - 1; i >= 0; i--) {
			if (indices[i] ! = i) {
				temp = digits[i];
				digits[i] = digits[indices[i]];
				digits[indices[i]] = temp;
				break;
			}
		}

		num = 0;
		int factor = 1;
		for (const auto &digit : digits) {
			num += (digit * factor);
			factor *= 10;
		}
		return num;
	}

private:
	vector<int> digits;

	bool comp(int i, int j)
	{
		if (digits[i] < digits[j]) {
			return true;
		}
		else if (digits[i] > digits[j]) {
			return false;
		}

		// reach here when digits[i] == digits[j]
		if (i < j) {
			return true;
		}

		assert(i > j);
		return false;
	}
};

