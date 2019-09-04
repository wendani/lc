class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int len = s.length();
		if (len != t.length()) {
			return false;
		}

		int alphaIdxS[128] = {0};
		int alphaIdxT[128] = {0};
		int currIdx = 1;
		for (int i = 0; i < len; i++) {
			if (alphaIdxS[s[i]] != alphaIdxT[t[i]]) {
				return false;
			}
			else {
				// alphaIdxS[s[i]] == alphaIdxT[t[i]]
				if (!alphaIdxS[s[i]]) {
					// a new character
					alphaIdxS[s[i]] = currIdx;
					alphaIdxT[t[i]] = currIdx;
					currIdx++;
				}
			}
		}
		return true;
	}
};


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
				// a new character
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
