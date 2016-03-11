void rotate(int* nums, int numsSize, int k) {
    int oidx, nidx, otemp, ntemp;
    int i, init_idx;

    if (k % numsSize == 0) return;

    oidx = 0;
    init_idx = oidx;
    otemp = nums[oidx];
    for (i = 1; i <= numsSize; ++i) {
        nidx = oidx + k;
        if (nidx >= numsSize)
            nidx %= numsSize;

        ntemp = nums[nidx];
        nums[nidx] = otemp;
        
        oidx = nidx;
        otemp = ntemp;
        if (oidx == init_idx) {
            ++oidx;
            init_idx = oidx;
            otemp = nums[oidx];
        }
    }
}
