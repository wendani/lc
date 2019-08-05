/*
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

void _subsets(vector<vector<int>> &subsets, vector<int>::const_iterator cbegin, vector<int>::const_iterator cend)
{
	if (cbegin == cend) {
		return;
	}

	if (cbegin + 1 == cend) {
		subsets.emplace_back();
		subsets.emplace_back(initializer_list<int>{*cbegin});
		return;
	}

	// reach here when cbegin + 1 != cend
	// we have more than one element in the vector
	vector<vector<int>> subsubsets;
	_subsets(subsubsets, cbegin + 1, cend);

	vector<vector<int>> currsubsets = {{}, {*cbegin}};
	// currsubsets.emplace_back();
	// currsubsets.emplace_back(initializer_list<int>{*cbegin});
	for (const auto &currsubset : currsubsets) {
		for (const auto &subsubset : subsubsets) {
			// vector<int> subset;
			// subset.insert(subset.end(), currsubset.begin(), currsubset.end());
			// subset.insert(subset.end(), subsubset.begin(), subsubset.end());
			// subsets.push_back(subset);
			subsets.emplace_back();
			auto &subset = subsets.back();
			subset.insert(subset.end(), currsubset.begin(), currsubset.end());
			subset.insert(subset.end(), subsubset.begin(), subsubset.end());
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> subsets;
	_subsets(subsets, nums.cbegin(), nums.cend());

	return subsets;
}
