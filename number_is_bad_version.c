// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	int lo = 1;
	int hi = n;

	int firstBadVersion = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (isBadVersion(mid)) {
			firstBadVersion = mid;
			hi = mid - 1;
		}
		else {
			// mid is not a bad version
			lo = mid + 1;
		}
	}
	return firstBadVersion;
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
