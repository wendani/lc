/*
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 *
 * Example 1:
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 */


int coinChange(vector<int>& coins, int amount) {
	vector<int> coinNum(amount + 1, amount + 1);

	int coinSize = coins.size();
	coinNum[0] = 0;
	for (int i = 0; i < coinSize; i++) {
		for (int j = coins[i]; j <= amount; j++) {
			if (coinNum[j - coins[i]] + 1 < coinNum[j]) {
				coinNum[j] = coinNum[j - coins[i]] + 1;
			}
		}
	}

	if (coinNum[amount] > amount) {
		return -1;
	}
	return coinNum[amount];
}

int coinChange(vector<int>& coins, int amount) {
	vector<int> coinNum(amount + 1, amount + 1);

	int coinSize = coins.size();
	coinNum[0] = 0;
	for (int i = 1; i < amount + 1; i++) {
		for (int j = 0; j < coinSize; j++) {
			int subamount = i - coins[j];
			if (subamount >= 0 && coinNum[subamount] + 1 < coinNum[i]) {
				coinNum[i] = coinNum[subamount] + 1;
			}
		}
	}

	if (coinNum[amount] > amount) {
		return -1;
	}
	return coinNum[amount];
}

int coinChange(vector<int>& coins, int amount) {
	if (!coins.size() || amount < 0) {
		return -1;
	}
	if (amount == 0) {
		return 0;
	}

	unordered_set<int> amounts;
	for (int i = 1; i <= amount; i++) {
		amounts.insert(i);
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
