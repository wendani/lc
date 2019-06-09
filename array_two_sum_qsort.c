static void _qsort(int *aSortedIdx, int *a, int size)
{
    int i;

    if (!a || size < 2)
        return;

    int piv = size - 1;
    for (i = piv - 1; i >= 0; i--)
        if (a[i] >= a[piv]) {
            int temp = aSortedIdx[i];
            aSortedIdx[i] = aSortedIdx[piv - 1];
            aSortedIdx[piv - 1] = aSortedIdx[piv];
            aSortedIdx[piv] = temp;
            piv--;
        }

    _qsort(aSortedIdx, a, piv);
    _qsort(&aSortedIdx[piv + 1], &a[piv + 1], size - (piv + 1));
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *aSortedIdx;
    int i, j;

    aSortedIdx = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < size; i++)
        aSortedIdx[i] = i;
    _qsort(aSortedIdx, nums, numsSize);

    i = 0;
    j = numsSize - 1;
    while (i < j) {
        if (nums[aSortedIdx[i]] + nums[aSortedIdx[j]] == target) {
            int *indices = (int *)malloc(2 * sizeof(int));
            indices[0] = aSortedIdx[i];
            indices[1] = aSortedIdx[j];
            *returnSize = 2;
            return indices;
        }
        else if (nums[aSortedIdx[i]] + nums[aSortedIdx[j]] < target) {
            ++i;
        }
        else {
            // nums[aSortedIdx[i]] + nums[aSortedIdx[j]] > target
            --j;
        }
    }
    *returnSize = 0;
    return NULL;
}
