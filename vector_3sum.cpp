vector<vector<int>> threeSum(vector<int>& nums) {
	unordered_map<int, int> numIdxMap;
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		numIdxMap.emplace(nums[i], i);
	}

	vector<vector<int>> results;
	for (int i = 0; i < len - 2; i++)
		for (int j = i + 1; j < len - 1; j++) {
			auto it = numIdxMap.find(0 - nums[i] - nums[j]);
			if (it != numIdxMap.end() && j < it->second) {
				results.emplace_back(initializer_list<int>({nums[i], nums[j], it->first}));
			}
		}

	return results;
}
