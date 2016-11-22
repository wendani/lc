#define ENOMEM 12
#define DEBUG_MERGE_SORT

/**
 * return a sorted array of size numSize
 * using the original storage space
 */
int msort(int *nums, int numSize) {
	int mid, shalf_size;
	int i, j, sindx;
	int *buf;

	if (numSize == 0)
		return;

	if (numSize == 1)
		return;

	mid = numSize >> 1;	
	shalf_size = numSize - mid;
	msort(nums, mid);
	msort(nums + mid, shalf_size);
	
	i = 0; 
	j = mid;
	sindx = 0;
	buf = (int *) malloc(mid * sizeof(int));
	while ((i < mid) || (j < numSize - mid)) {
		if (i < sindx) {
			if (sindx < mid)
				buf[sindx]  = nums[sindx]; //

			if (buf[i] <= nums[j]) {
				nums[sindx] = buf[i];
				i++;
			} else {
				nums[sindx] = nums[j]; //
				j++;
			}
		} else {
			// case i == sindx
			if (nums[i] <= nums[j])
				i++;
			else {
				buf[sindx]  = nums[sindx];
				nums[sindx] = nums[j];
				j++;
			}
		}
		sindx++;
	}
	for (; i < mid; i++) {
		nums[sindx] = buf[i];
		sindx++;
	}

	free(buf);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
 	int *arr;
    	int i;

    	if (!returnSize)
    		return NULL;

	if (!nums1 || !nums1Size || !nums2 || !nums2Size) {
		*returnSize = 0;
		return NULL;
	}

	arr = (int *) malloc((nums1Size + nums2Size) * sizeof(int));
	if (!arr) {
		*returnSize = -ENOMEM;
		return NULL;
	}
	
	// sort both arrays
	msort(nums1, nums1Size);

#ifdef DEBUG_MERGE_SORT
	printf("sort:");
	for (i = 0; i < nums1; i++)
		printf(" %d", nums1[i]);
	printf("\n");
#endif
	return arr;
}
