int search(int* nums, int numsSize, int target){
	int lo, hi, mid;

	if (!nums || numsSize < 1) {
		return -1;
	}

	lo = 0;
	hi = numsSize - 1;
	while (lo <= hi) {
		mid = (lo + hi) >> 1;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			if (nums[mid] <= nums[hi] && nums[hi] < target) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		else {
			// target < nums[mid]
			if (target < nums[lo] && nums[lo] <= nums[mid]) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
	}

	return -1;
}
