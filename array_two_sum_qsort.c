/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// quick sort
static void _qsort(int *aSortedIdx, int *a, int size)
{
    int i;

    if (!aSortedIdx || !a || size < 2)
        return;

    int piv = size - 1;
    for (i = piv - 1; i >= 0; i--)
        if (a[aSortedIdx[i]] >= a[aSortedIdx[piv]]) {
            int temp = aSortedIdx[i];
            aSortedIdx[i] = aSortedIdx[piv - 1];
            aSortedIdx[piv - 1] = aSortedIdx[piv];
            aSortedIdx[piv] = temp;
            piv--;
        }

    _qsort(aSortedIdx, a, piv);
    _qsort(&aSortedIdx[piv + 1], a, size - (piv + 1));
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *numsSortedIdx;
    int i, j;

    numsSortedIdx = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++)
        numsSortedIdx[i] = i;
    _qsort(numsSortedIdx, nums, numsSize);

    i = 0;
    j = numsSize - 1;
    while (i < j) {
        if (nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] == target) {
            int *indices = (int *)malloc(2 * sizeof(int));
            indices[0] = numsSortedIdx[i];
            indices[1] = numsSortedIdx[j];
            *returnSize = 2;
            return indices;
        }
        else if (nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] < target) {
            ++i;
        }
        else {
            // nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] > target
            --j;
        }
    }
    *returnSize = 0;
    return NULL;
}
