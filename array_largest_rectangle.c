int _largestRectangleArea(int heights[], int start, int excl_end) {
	int i;
	int min, min_idx;
	int maxRect, subMaxRect;

	if (start == excl_end) {
		return 0;
	}

	min = heights[start];
	min_idx = start;
	for (i = start + 1; i < excl_end; i++) {
		if (heights[i] < min) {
			min = heights[i];
			min_idx = i;
		}
	}

	maxRect = (excl_end - start) * min;
	subMaxRect = _largestRectangleArea(heights, start, min_idx);
	if (subMaxRect > maxRect) {
		maxRect = subMaxRect;
	}
	subMaxRect = _largestRectangleArea(heights, min_idx + 1, excl_end);
	if (subMaxRect > maxRect) {
		maxRect = subMaxRect;
	}
	return maxRect;
}

int largestRectangleArea(int* heights, int heightsSize){
	if (!heights || heightsSize < 1) {
		return 0;
	}

	return _largestRectangleArea(heights, 0, heightsSize);
}
