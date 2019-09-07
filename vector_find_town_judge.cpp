class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		if (N == 1) {
			return 1;
		}

		vector<int> beTrustedCounts(N + 1, 0);
		vector<bool> trustCounts(N + 1, false);
		for (const auto &t : trust) {
			beTrustedCounts[t[1]]++;
			trustCounts[t[0]] = true;
		}

		int judgeIdx = -1;
		for (int i = 1; i <= N; i++) {
			if (beTrustedCounts[i] == N - 1) {
				judgeIdx = i;
				break;
			}
		}
		// The town judge trusts nobody
		// If a town judge exists, there cannot be more than one person that satisfies properties 1 and 2
		if (judgeIdx > 0 && trustCounts[judgeIdx]) {
			return  -1;
		}
		return judgeIdx;
	}
};


/*
 * If the town judge exists, then:
 *
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 */

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
