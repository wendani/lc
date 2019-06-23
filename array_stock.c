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

		if (a[head] >= a[i]) {
			head = i;
			if (a[tail] - a[head] > max_prof) {
				min_idx = head;
				max_idx = tail;
				max_prof = a[tail] - a[head];
			}
		}
		else {
			// a[head] < a[i]
			if (a[i] - a[head] > max_prof) {
				min_idx = head;
				max_idx = i;
				max_prof = a[i] - a[head];
			}
		}

		if (a[j] >= a[tail]) {
			tail = j;
			if (a[tail] - a[head] > max_prof) {
				min_idx = head;
				max_idx = tail;
				max_prof = a[tail] - a[head];
			}
		}
		else {
			// a[j] < a[tail]
			if (a[tail] - a[j] > max_prof) {
				min_idx = j;
				max_idx = tail;
				max_prof = a[j] - a[tail];
			}
		}
	}
}
