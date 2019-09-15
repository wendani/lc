class Solution {
public:
	int twoSumLessThanK(vector<int>& A, int K) {
		int len = A.size();
		if (len < 2) {
			return -1;
		}

		sort(A.begin(), A.end());
		int i = 0;
		int j = len - 1;
		int max = -1;
		while (i < j) {
			int sum = A[i] + A[j];
			if (sum >= K) {
				j--;
			}
			else {
				// sum < K
				if (sum > max) {
					max = sum;
				}
				i++;
			}

		}
		return max;
	}
};


/*
 * Example 1:
 *
 * Input: A = [34,23,1,24,75,33,54,8], K = 60
 * Output: 58
 * Explanation:
 * We can use 34 and 24 to sum 58 which is less than 60.
 *
 * Example 2:
 *
 * Input: A = [10,20,30], K = 15
 * Output: -1
 * Explanation:
 * In this case it's not possible to get a pair sum less that 15.
 */
