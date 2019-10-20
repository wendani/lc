class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int charCnts[26] = {0};

		for (const auto &c : text) {
			charCnts[c - 'a']++;
		}
		charCnts['l' - 'a'] >>= 1;
		charCnts['o' - 'a'] >>= 1;

		int maxNum = text.length();
		for (const auto &c : targetChars) {
			if (charCnts[c - 'a'] < maxNum) {
				maxNum = charCnts[c - 'a'];
			}
		}
		return maximum;
	}
private:
	static const unordered_set<char> targetChars;
};

const unordered_set<char> Solution::targetChars = {'b', 'a', 'l', 'o', 'n'};


/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (63.79%)
 * Total Accepted:    11.1K
 * Total Submissions: 17.7K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 *
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: text = "nlaebolko"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: text = "loonbalxballpoon"
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: text = "leetcode"
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
 *
 */
