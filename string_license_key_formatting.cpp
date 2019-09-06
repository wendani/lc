class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int cntInGroup = 0;
		string target;

		int i = S.length() - 1;
		while (i >= 0) {
			if (S[i] != '-') {
				target.push_back(toupper(S[i]));

				cntInGroup++;
				if (cntInGroup == K) {
					target.push_back('-');
					cntInGroup = 0;
				}
			}
			i--;
		}
		if (target.back() == '-') {
			target.pop_back();
		}
		reverse(target.begin(), target.end());
		return target;
	}
};


class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int cntInGroup = 0;

		int i = S.length() - 1;
		while (i >= 0) {
			if (cntInGroup == K) {
				if (S[i] == '-') {
					i--;
				}
				else {
					// S[i] != '-'
					S.insert(i + 1, 1, '-');
				}
				cntInGroup = 0;
			}
			else {
				// cntInGroup < K
				if (S[i] == '-') {
					S.erase(i, 1);
				}
				else {
					// S[i] != '-'
					if (!isdigit(S[i])) {
						if (islower(S[i])) {
							S[i] = toupper(S[i]);
						}
					}
					cntInGroup++;
				}
				i--;
			}
		}
		if (S[0] == '-') {
			S.erase(0, 1);
		}
		return S;
	}
};


/*
 * Example 1:
 *
 * Input: S = "5F3Z-2e-9-w", K = 4
 *
 * Output: "5F3Z-2E9W"
 *
 * Explanation: The string S has been split into two parts, each part has 4 characters.
 * Note that the two extra dashes are not needed and can be removed.
 *
 * Example 2:
 *
 * Input: S = "2-5g-3-J", K = 2
 *
 * Output: "2-5G-3J"
 *
 * Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
 */
