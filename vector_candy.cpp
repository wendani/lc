class Solution {
public:
	int candy(vector<int>& ratings) {
		map<int, vector<int>> ratingIndices;

		int len = ratings.size();
		for (int i = 0; i < len; i++) {
			auto it = ratingIndices.find(ratings[i]);
			if (it != ratingIndices.end()) {
				it->second.emplace_back(i);
			}
			else {
				ratingIndices.emplace(ratings[i], {i});
			}
		}

		vector<int> candies(len, 1);
		for (const auto &it : ratingIndices) {
			for (const auto &idx : it.second) {
				if (idx > 0 && ratings[idx - 1] < ratings[idx]) {
					if (candies[idx - 1] >= candies[idx]) {
						candies[idx] = candies[idx - 1] + 1;
					}
				}
				if (idx + 1 < len && ratings[idx] > ratings[idx + 1]) {
					if (candies[idx] <= candies[idx + 1] {
						candies[idx] = candies[idx + 1] + 1;
					}
				}
			}
		}

		int sum = 0;
		for (const auto &candy : candies) {
			sum += candy;
		}
		return sum;
	}
};

/*
 * Example 1:
 *
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 *
 * Example 2:
 *
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 *              The third child gets 1 candy because it satisfies the above two conditions.
 */

