//#define TEST_SORT

#ifdef TEST_SORT
#include <stdio.h>
#include <stdlib.h>
#endif

#define ENOMEM 12

void qk_sort(int *nums, int numSize)
{
	int pvt, pvt_tail;
	int pos, indx;
	int i, temp;

	if (!nums || !numSize)
		return;

	if (numSize == 1)
		return;

	// contain at least two elements in the array to reach here
	// choose the last element as pivot
	pvt = numSize - 1;
	pvt_tail = pvt;

	indx = pvt - 1;
	pos  = 0;
	for (i = 1; i < numSize; i++) {
		if (nums[indx] > nums[pvt]) {
			temp = nums[pvt_tail];
			nums[pvt_tail] = nums[indx];
			nums[indx] = temp;

			--pvt;
			--pvt_tail;
			--indx;
		} else if (nums[indx] == nums[pvt]) {
			--pvt;
			--indx;
		} else {
			// case of nums[indx] < nums[pvt]
			temp = nums[pos];
			nums[pos] = nums[indx];
			nums[indx] = temp;

			++pos;
		}
	}

	qk_sort(nums, pvt);
	qk_sort(nums + pvt_tail + 1, numSize - pvt_tail - 1);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int i, j, indx;
	int *arr;

	if (!nums1 || !nums1Size || !nums2 || !nums2Size) {
		*returnSize = -ENOMEM;
		return NULL;
	}

	arr = (int *) malloc((nums1Size + nums2Size) * sizeof(int));
	if (!arr) {
		*returnSize = -ENOMEM;
		return NULL;
	}

	// serious code starts here
	// sort both arrays
	qk_sort(nums1, nums1Size);
	qk_sort(nums2, nums2Size);

	// find intersection
	i = 0;
	j = 0;
	indx = 0;
	while ((i < nums1Size) && (j < nums2Size)) {
		if (nums1[i] < nums2[j])
			++i;

		if (nums1[i] == nums2[j]) {
			arr[indx] = nums1[i];

			++i;
			++j;
			++indx;
		}

		if (nums1[i] > nums2[j])
			++j;
	}

	*returnSize = indx;
	return arr;
}

#ifdef TEST_SORT
int main(int argc, char *argv[])
{
	int i;
	int arr[] = {7, 6, 10, 5, 2, 5, 1, 5};
	int size = 8;

	printf("sort: size %d, ", size);
	qk_sort(arr, size);

	for (i = 0; i < size; i++)
		printf(" %d", arr[i]);
	printf("\n");

	return 0;
}
#endif
