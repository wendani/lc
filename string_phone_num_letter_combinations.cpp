static const unordered_map<string, vector<string>> numLtrsMap;

void _letterCombinations(vector<string> &combinations, const string &digits)
{
	int len = digits.length();

	if (!len) {
		return;
	}

	if (len == 1) {
		for (const auto &ltr : numLtrsMap.at(digits)) {
			combinations.push_back(ltr);
		}
	}

	// reach here when len > 1
	vector<string> subcombinations;
	_letterCombinations(subcombinations, digits.substr(1));
	for (const auto &ltr : numLtrsMap.at(digits.substr(0,1))) {
		for (const auto &subcombination : subcombinations) {
			combinations.push_back(ltr + subcombination);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> combinations;
	_letterCombinations(combinations, digits);
	return combinations;
}

const unordered_map<string, vector<string>> Solution::numLtrsMap = {
	{"1", {}},
	{"2", {"a", "b", "c"}},
	{"3", {"d", "e", "f"}},
	{"4", {"g", "h", "i"}},
	{"5", {"j", "k", "l"}},
	{"6", {"m", "n", "o"}},
	{"7", {"p", "q", "r", "s"}},
	{"8", {"t", "u", "v"}},
	{"9", {"w", "x", "y", "z"}}
};


/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.01%)
 * Total Accepted:    448.7K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
