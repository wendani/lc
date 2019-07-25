class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> numIdx;

		vector<int> indices;

		int len = nums.size();
		for (int i = 0; i < len; i++) {
			int cmpl = target - nums[i];
			auto it = numIdx.find(cmpl);
			if (it != numIdx.end()) {
				indicies.push_back(i);
				indicies.push_back(it->second);
				return indices;
			}
			else {
				// it == numIdx.end()
				numIdx.emplace(nums[i], i);
			}
		}
		return indices;
	}
};
