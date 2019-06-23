int maxProfit(int* prices, int pricesSize){
	int i;
	int head, max_prof;

	if (!prices || pricesSize < 2)
		return 0;

	head = 0;
	max_prof = 0;
	for (i = 1; i < pricesSize; i++) {
		if (prices[head] >= prices[i])
			head = i;
		else {
			// prices[head] < prices[i]
			if (prices[i] - prices[head] > max_prof)
				max_prof = prices[i] - prices[head];
		}
	}

	return max_prof;
}
