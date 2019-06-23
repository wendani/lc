static void _qsort(int aSortedIdx[], int aOrig[], int size)
{
	int pvt_lo, pvt_hi;
	int i;

	if (!aSortedIdx || !aOrig || size < 2)
		return;

	pvt_hi = size - 1;
	pvt_lo = pvt_hi;
	for (i = pvt_lo - 1; i >= 0; i--) {
		if (aOrig[aSortedIdx[i]] > aOrig[aSortedIdx[pvt_lo]]) {
			int temp = aSortedIdx[i];

			pvt_lo--;
			aSortedIdx[i] = aSortedIdx[pvt_lo];
			aSortedIdx[pvt_lo] = aSortedIdx[pvt_hi];
			aSortedIdx[pvt_hi] = temp;
			pvt_hi--;
		}
		else if (aOrig[aSortedIdx[i]] == aOrig[aSortedIdx[pvt_lo]]) {
			int temp = aSortedIdx[i];

			pvt_lo--;
			aSortedIdx[i] = aSortedIdx[pvt_lo];
			aSortedIdx[pvt_lo] = temp;
		}
	}

	_qsort(&aSortedIdx[0], aOrig, pvt_lo);
	_qsort(&aSortedIdx[piv_hi + 1], aOrig, size - (pvt_hi + 1));
}

int hIndex(int* citations, int citationsSize){
	int i;
	int *citeSortedIdx;

	if (!citations || citationsSize < 1)
		return 0;

	citeSortedIdx = (int *)malloc(citationsSize * sizeof(int));
	for (i = 0; i < citationsSize; i++) {
		citeSortedIdx[i] = i;
	}
	_qsort(citeSortedIdx, citations, citationsSize);

	for (i = 0; citations[citeSortedIdx[i]] < citationsSize - i && i < size; i++)
		;

	free(citeSortedIdx);

	return citationsSize - i;
}
