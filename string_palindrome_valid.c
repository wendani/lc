class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.length();

		int i = 0;
		int j = len - 1;
		while (i < j) {
			bool iValid = isAlphaNumeric(s[i]);
			bool jValid = isAlphaNumeric(s[j]);
			if (iValid && jValid) {
				if (tolower(s[i]) != tolower(s[j])) {
					return false;
				}
				i++;
				j--;
			}
			else {
				if (!iValid) {
					i++;
				}
				if (!jValid) {
					j--;
				}
			}
		}
		return true;
	}

private:
	bool isAlphaNumeric(const char &c)
	{
		if (('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z')
			|| ('0' <= c && c <='9')) {
			return true;
		}
		return false;
	}
};
