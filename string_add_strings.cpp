class Solution {
public:
	string addStrings(string num1, string num2) {
		int &&iNum1 = stringToInteger(num1);
		int &&iNum2 = stringToInteger(num2);

		return integerToString(iNum1 + iNum2);
	}
private:
	int stringToInteger(const string &sNum)
	{
		int num = 0;
		for (const auto &c : sNum) {
			int digit = c - '0';

			num *= 10;
			num += digit;
		}

		return num;
	}

	string integerToString(int num)
	{
		string sNum;
		while (num) {
			int rem = num % 10;
			sNum.push_back(rem + '0');
			num /= 10;
		}

		reverse(sNum.begin(), sNum.end());
		return sNum;
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
