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
				combinations.emplace_back(initializer_list<int>({*it}));
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
