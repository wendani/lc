#define TEST_SORT

#ifdef TEST_SORT
#include <stdio.h>
#include <stdlib.h>
#endif


#define ENOMEM 12
#define DEBUG_SORT

/**
 * return a sorted array of size numSize
 * using the original storage space
 */
int msort(int *nums, int numSize) {
	int mid, shalf_size;
	int i, j, sindx;
	int *buf;

	if (!nums || (numSize == 0))
		return;

	if (numSize == 1)
		return;

	// To reach here, contain at least two elements
	mid = numSize >> 1;
	shalf_size = numSize - mid;
	msort(nums, mid);
	msort(nums + mid, shalf_size);

	i = 0;
	j = mid;
	sindx = 0;
	buf = (int *) malloc(mid * sizeof(int));
	while ((i < mid) && (j < numSize)) {
		if (i < sindx) {
			if (sindx < mid)
				buf[sindx]  = nums[sindx]; //

			if (buf[i] <= nums[j]) {
				nums[sindx] = buf[i];
				i++;
			} else {
				nums[sindx] = nums[j]; //
				j++; //
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

void bsort(int *nums, int numSize) {
	int i,j;
	int temp;

	if (!nums || numSize == 0)
		return;

	for (i = 1; i < numSize; i++)
		for (j = 0; j < numSize - i; j++)
			if (nums[j] > nums[j + 1]) {
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int *arr;
	int i, j, indx;

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
#ifdef DEBUG_SORT
	printf("sort:");
	for (i = 0; i < nums1Size; i++)
		printf(" %d", nums1[i]);
	printf("\n");
#endif
	msort(nums2, nums2Size);

	// find intersection
	i = 0;
	j = 0;
	indx = 0;
	while ((i < nums1Size) && (j < nums2Size)) {
		if (nums1[i] < nums2[j]) {
			i++;
		}

		if (nums1[i] == nums2[j]) {
			arr[indx] = nums1[i];
			i++;
			while ((i < nums1Size) && (nums1[i - 1] == nums1[i]))
				i++;
			j++;
			while ((j < nums2Size) && (nums2[j - 1] == nums2[j]))
				j++;
			indx++;
		}

		if (nums1[i] > nums2[j]) {
			j++;
		}
	}
	*returnSize = indx;

	return arr;
}

#ifdef TEST_SORT
int main(int argc, char *argv[])
{
	int i;
	int arr[] = {7, 6, 10, 3, 2, 1, 5};
	int size = 7;

	printf("sort: size %d, ", size);
	bsort(arr, size);

	for (i = 0; i < size; i++)
		printf(" %d", arr[i]);
	printf("\n");

	return 0;
}
#endif
