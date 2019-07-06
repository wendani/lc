vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> results;
	int len = nums.size();
	for (int i = 0; i < len - 2; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int t = 0 - nums[i];
		int j = i + 1;
		int k = len - 1;
		while (j < k) {
			if (nums[j] + nums[k] < t) {
				j++;
			}
			else if (nums[j] + nums[k] > t) {
				k--;
			}
			else {
				// nums[j] + num[k] == t
				if ((j == i + 1) || (k == len - 1)
					|| (nums[j] != nums[j -1]) || nums[k] != nums[k - 1]) {
					results.emplace_back(initializer_list<int>({nums[i], nums[j], nums[k]}));
				}
				j++;
				k--;
			}
		}
	}

	return results;
}
