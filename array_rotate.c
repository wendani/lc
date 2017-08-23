/**
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */

void rotate(int* nums, int numsSize, int k) {
	int oidx, nidx, temp;
	int i, init_idx;

	k %= numsSize;
	if (k == 0) return;

	init_idx = numsSize - 1;
	nidx = init_idx;
	temp = nums[nidx];
	for (i = 1; i <= numsSize; ++i) {
		if (nidx < k)
			oidx = nidx + numsSize - k;
		else
			oidx = nidx - k;

		if (oidx == init_idx) {
			nums[nidx] = temp;

			--init_idx;
			nidx = init_idx;
			temp = nums[nidx];
		} else {
			nums[nidx] = nums[oidx];
			nidx = oidx;
		}
	}
}
