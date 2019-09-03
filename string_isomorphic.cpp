class Solution {
public:
	bool isIsomorphic(string s, string t) {
		return sigGen(s) == sigGen(t);
	}
private:
	string sigGen(const string &s)
	{
		int alphaIdx[128] = {0};

		int currIdx = 1;
		stringstream signature;
		for (const auto &c : s) {
			int idx = alphaIdx[c];
			if (idx) {
				signature << idx;
			}
			else {
				// idx == 0
				signature << currIdx;

				alphaIdx[c] = currIdx;
				currIdx++;
			}
		}

		return signature.str();
	}
};


/*
 * Example 1:
 *
 * Input: s = "egg", t = "add"
 * Output: true
 *
 * Example 2:
 *
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 *
 * Input: s = "paper", t = "title"
 * Output: true
 */
