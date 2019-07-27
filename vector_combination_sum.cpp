/*
 * Example 1:
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 *
 * Example 2:
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
*/


bool _combinationSum(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target, vector<vector<int>> &combinations)
{
	if (combinations.size()) {
		combinations.clear();
	}

	if (target < 0) {
		return false;
	}

	if (target == 0) {
		return true;
	}

	for (auto it = begin; it != end; ++it) {
		vector<vector<int>> subcombinations;

		if (_combinationSum(it, end, target - *it, subcombinations)) {
			if (subcombinations.size()) {
				for (auto &subcombination : subcombinations) {
					subcombination.push_back(*it);
					combinations.push_back(subcombination);
				}
			}
			else {
				// combinations.emplace_back(1, *it);
				combinations.emplace_back(initializer_list<int>{*it});
			}
		}
	}

	if (combinations.size() > 0) {
		return true;
	}
	return false;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> combinations;

	sort(candidates.begin(), candidates.end());
	_combinationSum(candidates.cbegin(), candidates.cend(), target, combinations);

	return combinations;
}
