/*
 * Example:
 *
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> permutes;
		_permute(permutes, nums.cbegin(), nums.cend());
		return permutes;
	}
private:
	void _permute(vector<vector<int>> &permutes, vector<int>::const_iterator cBeginIt, vector<int>::const_iterator cEndIt)
	{
		if (cBeginIt == cEndIt) {
			return;
		}

		if (cBeginIt + 1 == cEndIt) {
			permutes.emplace_back(initializer_list<int>{*cBeginIt});
			return
		}

		// reach here when cBeginIt + 1 != cEndIt
		// we have more than one element in the vector
		vector<vector<int>> subPermutes;
		_permute(subPermutes, cBeginIt + 1, cEndIt);
		for (const auto &subPermute : subPermutes) {
			auto it = subPermute.begin();
			while (it != subPermute.end()) {
				permutes.emplace_back();
				auto &permute = permutes.back();

				permute.insert(permute.end(), subPermute.begin(), it);
				permute.push_back(*cBeginIt);
				permute.insert(permute.end(), it, subPermute.end());

				++it;
			}

			permutes.push_back(subPermute);
			permutes.back().push_back(*cbegin);
		}
	}
};
