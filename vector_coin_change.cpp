int coinChange(vector<int>& coins, int amount) {
	int nums = 0;

	if (!coins.size() || amount < 1) {
		return -1;
	}

	unordered_set<int> amounts;
	for (int i = 1; i <= amount; i++) {
		amounts.push_back(i);
	}

	unordered_set<int> a[2];
	unordered_set<int> *curr = &a[0];
	unordered_set<int> *next = &a[1];

	int nums = 1;
	curr->insert(0);
	while (!curr->empty()) {
		auto curr_it = curr->begin();
		while (curr_it != curr->end()) {
			for (const auto &coin : coins) {
				int next_amount = *curr_it + coin;

				if (next_amount == amount) {
					return nums;
				}

				auto it = amounts.find(next_amount);
				if (it != amounts.end()) {
					amounts.erase(it);
					next->insert(next_amount);
				}
			}

			curr_it = curr->erase(curr_it);
		}

		auto *temp = curr;
		curr = next;
		next = temp;
		++nums;
	}

	return -1;
}
