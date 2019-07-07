int missingNumber(vector<int>& nums) {
	int size = nums.size() + 1;
	vector<bool> bitmap(size, false);

	for (const auto &num : nums) {
		bitmap[num] = true;
	}

	for (int i = 0; i < size; i++) {
		if (!bitmap[i])
			return i;
	}

	return -1;
}


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
