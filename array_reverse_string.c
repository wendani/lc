void reverseString(char* s, int sSize) {
	int lo, hi;
	char temp;

	if (!s || sSize < 2) {
		return;
	}

	lo = 0;
	hi = sSize - 1;
	while (lo < hi) {
		temp = s[lo];
		s[lo] = s[hi];
		s[hi] = temp;

		lo++;
		hi--;
	}
}
