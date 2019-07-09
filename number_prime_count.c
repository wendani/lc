int countPrimes(int n) {
	vector<bool> isPrimes(n, false);

	int incl_bound = (int)sqrt(n - 1) + 1;
	for (int i = 2; i <= incl_bound; i++) {
		for (j = i << 1; j < n; j += i) {
			isPrimes[j] = false;
		}
	}

	int cnt = 0;
	for (int i = 2; i < n; i++) {
		cnt++;
	}
	return cnt;
}

int countPrimes(int n){
	int i, j;
	int not_prime_count;

	if (n < 2) {
		return 0;
	}

	not_prime_count = 1;
	for (i = 3; i < n; i++) {
		int incl_bound = (int)sqrt(i) + 1;

		for (j = 2; j <= incl_bound; j++) {
			if (i % j == 0) {
				not_prime_count++;
				break;
			}
		}
	}

	return (n - 1) - not_prime_count;
}
