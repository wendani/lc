void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, curr;
    
    if (!n) return;
    if (!m) {
        for (j = 0; j < n; ++j)
            nums1[j] = nums2[j];
        return;
    }

    for (i = n + m - 1; i >= n; --i)
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

void merge(int *nums1, int m, int *nums2, int n) {
	int i, tail, k;
	int j;

	i = 0;
	tail = m - 1;
	j = 0;
	while (j < n) {
		if ((i <= tail) && (nums1[i] <= nums2[j]))
			i++;
		else {
			// nums1[i] > nums2[j]
			// right shift nums1[i]..nums1[tail] by one
			for (k = tail; k >= i; k--)
				nums1[k + 1] = nums1[k];

			nums1[i] = nums2[j];
			i++;
			tail++;
			j++;
			assert(tail == l - 1 + j);
		}
	}
}
