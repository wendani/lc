int _qsort(int *nums, int numsSize, int k) {
	int i;
	int piv_lo, piv_hi, piv_val;

	piv_hi = numsSize - 1;
	piv_lo = piv_hi;
	piv_val = nums[piv_hi];
	for (i = piv_lo - 1; i >= 0; i--) {
		if (piv_val > nums[i]) {
			nums[piv_hi] = nums[i];
			piv_hi--;
			piv_lo--;
			nums[i] = nums[piv_lo];
			nums[piv_lo] = piv_val;
		}
		else if (nums[i] == piv_val) {
			piv_lo--;
			nums[i] = nums[piv_lo];
			nums[piv_lo] = piv_val;
		}
	}
	if (piv_lo <= k - 1 && k - 1 <= piv_hi) {
		return piv_val;
	}
	else if (k - 1 < piv_lo) {
		return _qsort(nums, piv_lo, k);
	}
	else {
		// piv_hi < k - 1
		return _qsort(&nums[piv_hi + 1], numsSize - (piv_hi + 1), k - 1 - piv_hi);
	}
}

int findKthLargest(int* nums, int numsSize, int k){
	return _qsort(nums, numsSize, k);
}
