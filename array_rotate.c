void rotate(int* nums, int numsSize, int k) {
    int oidx. nidx;
    int i, otemp, ntemp;

    if (k % numsSize == 0) return;

    oidx = 0;
    otemp = nums[oidx];
    for (i = 1; i <= n; ++i) {
        nidx = (oidx + k) % numsSize;
        
        ntemp = nums[nidx];
        nums[nidx] = otemp;
        
        oidx = nidx;
        otemp = ntemp;
    }
        
}
