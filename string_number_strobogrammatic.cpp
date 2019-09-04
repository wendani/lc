class Solution {
public:
	bool isStrobogrammatic(string num) {
		int i = 0;
		int j = num.length();
		while (i <= j) {
			if (strobo[num[i]] != num[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
private:
	static const unordered_map<char, char> strobo = {
		{'6', '9'},
		{'9', '6'},
		{'8', '8'},
		{'1', '1'},
		{'0', '0'},
	};
};

const


/*
 * Example 1:
 *
 * Input:  "69"
 * Output: true
 *
 * Example 2:
 *
 * Input:  "88"
 * Output: true
 *
 * Example 3:
 *
 * Input:  "962"
 * Output: false
 */
