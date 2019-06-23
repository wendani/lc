int maxProfit(int* prices, int pricesSize){
	int i, j;
	int min_idx, max_idx, max_prof;
	int head, tail;

	if (!prices || pricesSize < 2)
		return 0;

	head = 0;
	tail = pricesSize - 1;
	min_idx = head;
	max_idx = tail;
	max_prof = prices[max_idx] - prices[min_idx];
	if (max_prof < 0)
		max_prof = 0;

	i = head;
	j = tail;
	while (i < j) {
		i++;
		j--;

		if (prices[head] >= prices[i]) {
			head = i;
			if (prices[tail] - prices[head] > max_prof) {
				min_idx = head;
				max_idx = tail;
				max_prof = prices[tail] - prices[head];
			}
		}
		else {
			// prices[head] < prices[i]
			if (prices[i] - prices[head] > max_prof) {
				min_idx = head;
				max_idx = i;
				max_prof = prices[i] - prices[head];
			}
		}

		if (prices[j] >= prices[tail]) {
			tail = j;
			if (prices[tail] - prices[head] > max_prof) {
				min_idx = head;
				max_idx = tail;
				max_prof = prices[tail] - prices[head];
			}
		}
		else {
			// prices[j] < prices[tail]
			if (prices[tail] - prices[j] > max_prof) {
				min_idx = j;
				max_idx = tail;
				max_prof = prices[j] - prices[tail];
			}
		}
	}
}
