int removeDuplicates(int* nums, int numsSize) {
    int tidx, i;

    if (!numsSize) return 0;
    
    tidx = 0;
    for (i = 1; i < numsSize; ++i) {
        if (nums[tidx] != nums[i]) {
            ++tidx;
            if (tidx < i)
                nums[tidx] = nums[i];
        }
    }

    return tidx + 1;
}
