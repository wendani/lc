class Solution {
public:
	bool checkRecord(string s) {
		int ACnt = 0;
		int contLCnt = 0;

		for (const auto &c : s) {
			if (c == 'A') {
				contLCnt = 0;
				ACnt++;
				if (ACnt > 1) {
					return false;
				}
			}
			else if (c == 'L') {
				contLCnt++;
				if (contLCnt > 2) {
					return false;
				}
			}
			else {
				contLCnt = 0;
			}
		}
		return true;
	}
};


/*
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 */
