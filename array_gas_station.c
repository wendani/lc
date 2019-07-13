int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
	int i;
	int curr, min, min_idx;

	if (gasSize != costSize) {
		return -1;
	}

	curr = 0;
	min = curr;
	min_idx = 0;
	for (i = 0; i < gasSize; ) {
		curr += (gas[i] - cost[i]);

		i++;
		if (curr < min) {
			min = curr;
			min_idx = i;
		}
	}
	if (curr >= 0) {
		return min_idx;
	}
	return -1;
}
