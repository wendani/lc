int search(int* nums, int numsSize, int target){
	int lo, hi, mid;

	if (!nums || numsSize < 1) {
		return -1;
	}

	lo = 0;
	hi = size;
	while (lo < hi) {
		mid = (lo + hi) >> 1;

		if (a[mid] == target) {
			return mid;
		}
		else if (a[mid] < target) {
			if (a[lo] == target) {
				return lo;
			}
			else if (a[lo] < target) {
				hi = mid;
			}
			else {
				// target < a[lo]
				lo = mid + 1;
			}
		}
		else {
			// target < a[mid]
			if (a[lo] == target) {
				return lo;
			}
			else if (a[lo] < target) {
				hi = mid;
			}
			else {
				// target < a[lo]
				lo = mid + 1;
			}
		}
	}

	return -1;
}
