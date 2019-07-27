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
					eStk.top().str.push_back(c);
				}
			}
			else if (c == ']') {
				assert(!eStk.empty());

				element &elmt = eStk.top();
				string subStr;
				for (int i = 0; i < elmt.factor; i++) {
					subStr += elmt.str;
				}
				eStk.pop();

				if (eStk.empty()) {
					decoded += subStr;
				}
				else {
					// eStk.empty() == false
					eStk.top().str += subStr;
				}
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
