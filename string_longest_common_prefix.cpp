class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		if (len == 0) {
			return "";
		}

		string comPrefix = strs[0];
		for (int i = 1; i < len && !comPrefix.empty(); i++) {
			commonPrefix(comPrefix, strs[i]);
		}

		return comPrefix;
	}
private:
	void commonPrefix(string &prefix, const string &s)
	{
		int len = prefix.length();
		int lenS = s.length();
		if (lenS < len) {
			len = lenS;
		}

		for (int i = 0; i < len; i++) {
			if (prefix[i] != s[i]) {
				prefix.resize(i);
				return;
			}
		}
		prefix.resize(len);
	}
};


/*
 * Example 1:
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 */
