int missingNumber(vector<int>& nums) {
	int size = nums.size() + 1;
	bitset<size> bs;
	for (const auto &num : nums) {
		bs.set(num);
	}

	for (int i = 0; i < size; i++) {
		if (!bs.test(i))
			return i;
	}

	return -1;
}
