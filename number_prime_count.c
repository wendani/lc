int countPrimes(int n) {
	vector<bool> isPrime(n, true);

	int incl_bound = n > 2 ? (int)sqrt(n - 1) + 1 : 1;
	int i = 2;
	int cnt = 0;
	for (; i <= incl_bound; i++) {
		if (!isPrime[i]) {
			continue;
		}

		cnt++;
		for (int j = i << 1; j < n; j += i) {
			isPrime[j] = false;
		}
	}

	for (; i < n; i++) {
		if (isPrime[i]) {
			cnt++;
		}
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
