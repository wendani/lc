void rotate(int* nums, int numsSize, int k) {
    int oidx, nidx, otemp, ntemp;
    int i, j, cnt;

    if (k % numsSize == 0) return;

    oidx = 0;
    otemp = nums[oidx];

    if (numsSize % k == 0) {
        cnt = numsSize / k;
        for (i = 1; i <= k; ++i) {
            for (j = 1; j <= cnt; ++j) {
                nidx = oidx + k;
                if (j == cnt)
                    nidx -= numsSize;

                ntemp = nums[nidx];
                nums[nidx] = otemp;

                oidx = nidx;
                otemp = ntemp;
            }
            ++oidx;
            otemp = nums[oidx];
        }
        return;
    }

    for (i = 1; i <= numsSize; ++i) {
        nidx = (oidx + k) % numsSize;
        
        ntemp = nums[nidx];
        nums[nidx] = otemp;
        
        oidx = nidx;
        otemp = ntemp;
    }
}
