/**
 * return the index of the minimum element
 * -1, if array is NULL
 */
int get_min(int *nums, int numsSize)
{
	int i, indx;

	if (!nums || !numsSize)
		return -1;

	indx = 0;
	for (i = 1; i < numsSize; ++i)
		if (nums[i] < nums[indx])
			indx = i;

	return indx;
}

int minMoves(int* nums, int numsSize) {
	int i, indx, moves;

	if (!nums || !numsSize)
		return 0;

	indx = get_min(nums, numsSize);

	moves = 0;
	for (i = 0; i < numsSize; ++i) {
		if (i == indx)
			continue;
		moves += (nums[i] - nums[indx]);
	}

	return moves;
}
