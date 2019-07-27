class Solution {
public:
	string longestPalindrome(string s) {
		map<char, vector<int>> charIndices;
		string longestPalindrome;

		int len = s.length();
		if (len < 1) {
			return longestPalindrome;
		}

		for (int i = 0; i < len; i++) {
			charIndices[s[i]].push_back(i);
		}

		longestPalindrome = s.substr(0, 1);
		int maxLen = 1;
		for (const auto &it : charIndices) {
			int startIdx = 0;
			int endIdx = it.second.size() - 1;

			while (startIdx < endIdx) {
				int start = it.second[startIdx];
				int end = it.second[endIdx];
				int sLen = end - start + 1;
				if (sLen < maxLen) {
					break;
				}

				if (isPalindrome(s, start, end)) {
					maxLen = sLen;
					longestPalindrome = s.substr(start, maxLen);
					break;
				}

				if (it.second[startIdx + 1] - start > end - it.second[endIdx - 1]) {
					endIdx--;
				}
				else {
					startIdx++;
				}
			}
		}
		return longestPalindrome;
	}

private:
	bool isPalindrome(const string &s, const int &start, const int &end)
	{
		int i = start;
		int j = end;
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};
