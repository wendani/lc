// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	uint64_t lo = 1;
	uint64_t hi = n;

	while (lo <= hi) {
		uint64_t mid = (lo + hi) >> 1;
		if (isBadVersion(mid)) {
			hi = mid - 1;
		}
		else {
			// mid is not a bad version
			lo = mid + 1;
		}
	}
	return lo;
}

/*
 * Given n = 5, and version = 4 is the first bad version.
 *
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 *
 * Then 4 is the first bad version. 
 */
