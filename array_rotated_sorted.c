int search(int* nums, int numsSize, int target){
	int lo, hi, mid;

	if (!nums || numsSize < 1) {
		return -1;
	}

	lo = 0;
	hi = numsSize;
	while (lo < hi) {
		mid = (lo + hi) >> 1;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			if (nums[lo] == target) {
				return lo;
			}
			else if (nums[lo] < target) {
				hi = mid;
			}
			else {
				// target < nums[lo]
				lo = mid + 1;
			}
		}
		else {
			// target < nums[mid]
			if (nums[lo] == target) {
				return lo;
			}
			else if (nums[lo] < target) {
				hi = mid;
			}
			else {
				// target < nums[lo]
				lo = mid + 1;
			}
		}
	}

	return -1;
}
