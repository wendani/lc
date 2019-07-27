class Solution {
public:
	string longestPalindrome(string s) {
		string longestPalindrome;
		int maxLen = 0;

		int len = s.length();
		for (int i = 0; i < len; i++) {
			string curr;
			int cLen = findLongestPalindrome(curr, s, i, i);
			if (cLen > maxLen) {
				longestPalindrome = curr;
				maxLen = cLen;
			}
		}

		for (int i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1]) {
				string curr;
				int cLen = findLongestPalindrome(curr, s, i, i + 1);
				if (cLen > maxLen) {
					longestPalindrome = curr;
					maxLen = cLen;
				}
			}
		}
		return longestPalindrome;
	}

private:
	int findLongestPalindrome(string &lpSub, const string &s, const int &start, const int&end)
	{
		int i = start - 1;
		int j = end + 1;
		int len = s.length();
		while (i >= 0 && j < len && s[i] == s[j]) {
			i--;
			j++;
		}

		int lpLen = j - i - 1;
		lpSub = s.substr(i + 1, lpLen);
		return lpLen;
	}
};


class Solution {
public:
	string longestPalindrome(string s) {
		vector<vector<int>> curr;
		string longestPalindrome;
		string longestPalindromeEven;

		int len = s.length();

		for (int i = 0; i < len; i++) {
			curr.emplace_back(initializer_list<int>{i, i});
		}
		while (!curr.empty()) {
			longestPalindrome = s.substr(curr[0][0], curr[0][1] - curr[0][0] + 1);

			auto it = curr.begin();
			while (it != curr.end()) {
				int nstart = it->at(0) - 1;
				int nend = (*it)[1] + 1;
				if (nstart < 0 || nend > len - 1 || s[nstart] != s[nend]) {
					it = curr.erase(it);
				}
				else {
					it->at(0) = nstart;
					(*it)[1] = nend;
					++it;
				}
			}
		}

		for (int i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1]) {
				curr.emplace_back(initializer_list<int>{i, i + 1});
			}
		}
		while (!curr.empty()) {
			longestPalindromeEven = s.substr(curr[0][0], curr[0][1] - curr[0][0] + 1);

			auto it = curr.begin();
			while (it != curr.end()) {
				int nstart = it->at(0) - 1;
				int nend = (*it)[1] + 1;
				if (nstart < 0 || nend > len - 1 || s[nstart] != s[nend]) {
					it = curr.erase(it);
				}
				else {
					it->at(0) = nstart;
					(*it)[1] = nend;
					++it;
				}
			}
		}

		return longestPalindrome.length() > longestPalindromeEven.length() ? longestPalindrome : longestPalindromeEven;
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
