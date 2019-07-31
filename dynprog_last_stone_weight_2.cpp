/*
 * Example 1:
 *
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
 */

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		vector<int> smashes(1, 0);

		for (const auto &stone : stones) {
			int len = smashes.size();
			for (int i = 0; i < len; i++) {
				smashes.push_back(smashes[i] - stone);
				smashes[i] += stone;
			}
		}

		int lastWeight = smashes[0];
		int len = smashes.size();
		for (int i = 1; i < len; i++) {
			if (smashes[i] >= 0 && smashes[i] < lastWeight) {
				lastWeight = smashes[i];
			}
		}

		return lastWeight;
	}
};
