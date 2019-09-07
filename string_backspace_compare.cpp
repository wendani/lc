class Solution {
public:
	bool backspaceCompare(string S, string T) {
		return backspaceProcess(S) == backspaceProcess(T);
	}
private:
	string backspaceProcess(const string &s)
	{
		string postProc;
		for (const auto &c : s) {
			if (c == '#') {
				if (!postProc.empty()) {
					postProc.pop_back();
				}
			}
			else {
				postProc.push_back(c);
			}
		}
		return postProc;
	}
};


/*
 * Example 1:
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 * Example 2:
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 * Example 3:
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 * Example 4:
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 */
