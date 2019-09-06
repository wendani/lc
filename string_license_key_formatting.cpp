class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int cntInGroup = 0;

		int i = S.length() - 1;
		while (i >= 0) {
			if (cntInGroup == 4) {
				if (S[i] == '-') {
					i--;
				}
				else {
					// S[i] != '-'
					S.insert(i + 1, '-');
				}
				cntInGroup = 0;
			}
			else {
				// cntInGroup < 4
				if (S[i] == '-') {
					S.erase(i, 1);
				}
				else {
					if (!isdigit(S[i])) {
						if (islower(S[i]) {
							S[i] = toupper(S[i]);
						}
					}
					cntInGroup++;
				}
				i--;
			}
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
