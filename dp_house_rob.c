int rob(int *nums, int numsSize) {
    int old_val;

    int rob = 0, nrob = 0;

    int i;

    for (i = 0; i< numsSize; i++) {
        old_val = nrob;

        if (rob > nrob)
            nrob = rob;

        rob = old_val + nums[i];
    }

    if (rob > nrob)
        return rob;

    return nrob;
}
