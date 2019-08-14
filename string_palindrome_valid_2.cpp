/*
 * Example 1:
 *
 * Input: "aba"
 * Output: True
 *
 * Example 2:
 *
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 */


class Solution {
public:
	bool validPalindrome(string s) {
		int j = s.length() - 1;
		int i = 0;

		while (i < j) {
			if (s[i] == s[j]) {
				i++;
				j--;
			}
			else if (isPalindrome(s.substr(i, j - i))
					|| isPalindrome(i + 1, j - i)) {
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}
private:
	bool isPalindrome(const string &s)
	{
		int j = s.length() - 1;
		int i = 0;

		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}
};


