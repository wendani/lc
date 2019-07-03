bool _combinationSum(const vector<int> &candidates, int target, vector<vector<int>> &combinations)
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

	for (const auto &candidate : candidates) {
		vector<vector<int>> subcombinations;

		if (_combinationSum(candidates, target - candidate, subcombinations)) {
			if (subcombinations.size()) {
				for (auto &subcombination : subcombinations) {
					subcombination.push_back(candidate);
					combinations.push_back(subcombination);
				}
			}
			else {
				// combinations.emplace_back(1, candidate);
				combinations.emplace_back(initializer_list<int>({candidate}));
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

	_combinationSum(candidates, target, combinations);

	return combinations;
}
