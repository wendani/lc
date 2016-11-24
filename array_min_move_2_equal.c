#define TEST
#ifdef TEST
#include <stdio.h>
#endif

#define EINVAL 22

/**
 * return 1, if all elements are equal;
 * 0, otherwise
 */
static int is_equal(int *nums, int num_size)
{
	int flag = 1;
	int i;

	if (!nums || !num_size)
		return flag;

	// Reach here to contain at least one element
	for (i = 1; i < num_size; ++i)
		if (nums[i - 1] != nums[i]) {
			flag = 0;
			break;
		}

	return flag;
}

/**
 * return the index of the maximum element
 * -1, if array is NULL
 */
static int get_max(int *nums, int num_size)
{
	int i, indx = 0;

	if (!nums || !num_size)
		return -1;

	// Reach here to contain at least one element
	for (i = 1; i < num_size; ++i)
		if (nums[i] > nums[indx])
			indx = i;

	return indx;
}

int minMoves(int* nums, int numsSize) {
	int i, indx, moves;

	if (!nums || !numsSize)
		return 0;

	if (numsSize == 1)
		return 0;

	if (numsSize == 2)
		return abs(nums[0] - nums[1]);

	moves = 0;
	while (!is_equal(nums, numsSize)) {
		indx = get_max(nums, numsSize);
		if (indx < 0)
			return -EINVAL;

		for (i = 0; i < numsSize; i++) {
			if (i == indx)
				continue;
			++nums[i];
		}
		++moves;
	}

	return  moves;
}

#ifdef TEST
int main(int argc, char *argv[])
{
	int arr[] = {1, 2147483647};

	printf("moves: %d\n", minMoves(arr, 2));

	return 0;
}
#endif
