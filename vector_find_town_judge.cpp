class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> trustCounts(N + 1, 0);

		int judgeIdx = -1;
		for (const auto &t : trust) {
			trustCounts[t[1]]++;
			if (trustCounts[t[1]] == N - 1) {
				if (judgeIdx > 0) {
					return -1;
				}
				else {
					judgeIdx = t[1];
				}
			}
		}
		return judgeIdx;
	}
};


/*
 * trust[i] are all different
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 */

/*
 * Example 1:
 *
 * Input: N = 2, trust = [[1,2]]
 * Output: 2
 *
 * Example 2:
 *
 * Input: N = 3, trust = [[1,3],[2,3]]
 * Output: 3
 *
 * Example 3:
 *
 * Input: N = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 *
 * Example 4:
 *
 * Input: N = 3, trust = [[1,2],[2,3]]
 * Output: -1
 *
 * Example 5:
 *
 * Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * Output: 3
 */
