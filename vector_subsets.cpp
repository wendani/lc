void _subsets(vector<vector<int>> &subsets, vector<int>::const_iterator cbegin, vector<int>::const_iterator cend)
{
	if (cbegin == cend) {
		return;
	}

	if (cbegin + 1 == cend) {
		subsets.emplace_back();
		subsets.emplace_back(initializer_list<int>{*cbegin});
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
			vector<int> subnet;
			subnet.insert(subnet.end(), currsubset.begin(), currsubset.end());
			subnet.insert(subnet.end(), subsubset.begin(), subsubset.end());
			subsets.push_back(subnet);
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> subsets;
	_subsets(subsets, nums.cbegin(), nums.cend());

	return subsets;
}
