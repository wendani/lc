/*
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
	string decodeString(string s) {
		stack<element> eStk;
		string decoded;

		for (const auto &c : s) {
			if (isNum(c)) {
				eStk.emplace(c - '0');
			}
			else if (isAlphabetic(c)) {
				if (eStk.empty()) {
					decoded.push_back(c);
				}
				else {
					// eStk.empty() == false
					element &elmt = eStk.top();
					elmt.str.push_back(c);
				}
			}
			else if (c == ']') {
				assert(!eStk.empty());

				element &elmt = eStk.top();
				for (int i = 0; i < elmt.factor; i++) {
					decoded += elmt.str;
				}
				eStk.pop();
			}
		}
		return decoded;
	}

private:
	bool isAlphabetic(const char &c)
	{
		if (('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z')) {
			return true;
		}
		return false;
	}

	bool isNum(const char &c)
	{
		if ('0' <= c && c <= '9') {
			return true;
		}
		return false;
	}

	struct element {
		element(const int &f, const string &s = "") : factor(f), str(s) {
		}

		int factor;
		string str;
	};
};
