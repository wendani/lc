class Solution {
public:
	string addStrings(string num1, string num2) {
		size_t len1 = num1.length();
		size_t len2 = num2.length();

		string num;
		int credit = 0;
		int i1 = len1 - 1;
		int i2 = len2 - 1;
		while (i1 >= 0 || i2 >= 0) {
			int digit = credit;
			if (i1 >= 0) {
				digit += num1[i1] - '0';
			}
			if (i2 >= 0) {
				digit += num2[i2] - '0';
			}
			num.push_back(digit % 10 + '0');

			credit = digit / 10;
			i1--;
			i2--;
		}
		if (credit) {
			num.push_back(credit + '0');
		}

		reverse(num.begin(), num.end());
		return num;
	}
};


/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.60%)
 * Total Accepted:    113.5K
 * Total Submissions: 254.4K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
