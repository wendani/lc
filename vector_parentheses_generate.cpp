class Solution {
public:
	vector<string> generateParenthesis(int n) {
		return _generateParenthesis(0, n);
	}
private:
	vector<string> _generateParenthesis(int closeParenthesisCredits, int openParenthesisNum)
	{
		if (closeParenthesisCredits == 0 && openParenthesisNum == 0) {
			return {""};
		}

		vector<string> parentheses;
		for (int i = 1; i <= openParenthesisNum; i++) {
			string preOpen(i, '(');

			for (int j = i + closeParenthesisCredits; j > 0; j--) {
				string preClose(j, ')');

				vector<string> post = _generateParenthesis(i - j + closeParenthesisCredits, openParenthesisNum - i);

				for (const auto &pst : post) {
					parentheses.push_back(preOpen + preClose + pst);
				}
			}
		}
		return parentheses;
	}
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> parentheses;
		_generateParenthesis(parentheses, 0, n);
		return parentheses;
	}
private:
	void _generateParenthesis(vector<string> &parentheses, int closeParenthesisCredits, int openParenthesisNum)
	{
		if (closeParenthesisCredits == 0 && openParenthesisNum == 0) {
			parentheses.emplace_back();
		}

		for (int i = 1; i <= openParenthesisNum; i++) {
			string preOpen(i, '(');

			for (int j = i + closeParenthesisCredits; j > 0; j--) {
				string preClose(j, ')');

				vector<string> post;
				_generateParenthesis(post, i - j + closeParenthesisCredits, openParenthesisNum - i);

				for (const auto &pst : post) {
					parentheses.push_back(preOpen + preClose + pst);
				}
			}
		}
	}
};


/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.04%)
 * Total Accepted:    397.6K
 * Total Submissions: 694.8K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
