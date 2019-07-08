int majorityElement(int* nums, int numsSize){
	int i;
	int target;
	int count;

	for (i = 0, count = 0; i < numsSize; i++) {
		if (count == 0) {
			target = nums[i];
			count++;
		}
		else {
			// count > 0
			if (nums[i] == target) {
				count++;
			}
			else {
				// nums[i] != target
				count--;
			}
		}
	}

	return target;
}
