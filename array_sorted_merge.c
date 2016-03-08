void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, curr;
    
    if (!n) return;
    if (!m) {
        for (j = 0; j < n; ++j)
            nums1[j] = nums2[j];
        return;
    }

    for (i = n + m - 1; i > n - 1; --i)
        nums1[i] = nums1[i - n];

    i = n;
    j = 0;
    curr = 0;
    while (i < m + n && j < n) {
        if (nums1[i] <= nums2[j]) {
            nums1[curr] = nums1[i];
            ++i;
        }
        else {
            nums1[curr] = nums2[j];
            ++j;
        }
        ++curr;
    }
    if (i == m + n) 
        for (; j < n; ++j, ++curr)
            nums1[curr] = nums2[j];
}
