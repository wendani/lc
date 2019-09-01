class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		int len = A.size();

		if (len == 0) {
			return false;
		}

		if (len == 1) {
			return true;
		}

		// reach here when len > 1
		int monoDirection = 0;
		for (int i = 1; i < len; i++) {
			if (A[i - 1] > A[i]) {
				if (monoDirection > 0) {
					return false;
				}
				else if (monoDirection == 0) {
					monoDirection = -1;
				}
			}
			else if (A[i - 1] < A[i]) {
				if (monoDirection < 0) {
					return false;
				}
				else if (monoDirection == 0) {
					monoDirection = 1;
				}
			}
		}
		return true;
	}
};


/*
 * Example 1:
 *
 * Input: [1,2,2,3]
 * Output: true
 *
 * Example 2:
 *
 * Input: [6,5,4,4]
 * Output: true
 *
 * Example 3:
 *
 * Input: [1,3,2]
 * Output: false
 *
 * Example 4:
 *
 * Input: [1,2,4,5]
 * Output: true
 *
 * Example 5:
 *
 * Input: [1,1,1]
 * Output: true
 */
