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
			else if (isPalindrome(s, i, j - 1)
					|| isPalindrome(s, i + 1, j)) {
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}
private:
	bool isPalindrome(const string &s, int i, int j)
	{
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};
