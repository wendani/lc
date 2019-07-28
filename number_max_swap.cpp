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
 *
 *
 * Input: 1993
 * Output: 9193
 * Expected: 9913
 *
 *
 * Input: 98368
 * Output: 98368
 * Expected: 98863
 */

static bool comp(const vector<int> &i, const vector<int> &j)
{
	if (i[0] < j[0]) {
		return true;
	}
	else if (i[0] > j[0]) {
		return false;
	}

	// reach here when i[0] == j[0]
	if (i[1] < j[1]) {
		return true;
	}

	assert(i[1] > j[1]);
	return false;
}

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
		vector<vector<int>> dis; // digit-index
		for (int i = 0; i < len; i++) {
			dis.emplace_back(initializer_list<int>{digits[i], i});
		}
		sort(dis.begin(), dis.end(), comp);

		for (int i = len - 1; i >= 0; i--) {
			if (dis[i][1] != i) {
				int j = i;
				while (j - 1 >= 0 && dis[j - 1][0] == dis[i][0]) {
					j--;
				}

				digits[dis[j][1]] = digits[i];
				digits[i] = dis[j][0];
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
};

