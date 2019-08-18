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
		int weightSum = 0;
		for (const auto &stone : stones) {
			weightSum += stone;
		}
		int weightLimit = weightSum >> 1;

		vector<vector<bool>> stoneWeight;
		int len = stones.size();
		for (int i = 0; i < len; i++) {
			stoneWeight.emplace_back(weightLimit + 1, false);
			stoneWeight[i][0] = true;
		}

		int maxWeight = stones[0];
		stoneWeight[0][stones[0]] = true;
		for (int i = 1; i < len; i++) {
			int j;
			for (j = 1; j < stones[i]; j++) {
				if (stoneWeight[i - 1][j]) {
					stoneWeight[i][j] = true;
				}
			}
			for (j = stones[i]; j <= weightLimit; j++) {
				if (stoneWeight[i - 1][j - stones[i]] || stoneWeight[i - 1][j]) {
					stoneWeight[i][j] = true;
					if (maxWeight < j) {
						maxWeight = j;
					}
				}
			}
		}

		int last = weightSum - maxWeight;
		return last > maxWeight ? last - maxWeight : maxWeight - last;
	}
};


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
