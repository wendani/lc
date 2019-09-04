class Solution {
public:
	bool isStrobogrammatic(string num) {
		int i = 0;
		int j = num.length() - 1;
		while (i <= j) {
			if (strobo[num[i] - '0'] != num[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
private:
	static const char strobo[10];
};

const char Solution::strobo[10] = {
	'0',
	'1',
	 0 ,
	 0 ,
	 0 ,
	 0 ,
	'9',
	 0 ,
	'8',
	'6',
};

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
