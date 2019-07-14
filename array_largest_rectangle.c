int largestRectangleArea(vector<int>& heights) {
	int len = heights.size();

	map<int, int> btlNeckStart;
	int maxRect = 0;
	for (i = 0; i < len; i++) {
		auto it = btlNeckStart.lower_bound(heights[i]);

		if (it != btlNeckStart.end()) {
			it->first = heights[i];
			btlNeckStart.erase(it + 1, btlNeckStart.end());
			int rect = (i - it->second + 1) * heights[i];
			if (rect > maxRect) {
				maxRect = rect;
			}
		}
		else {
			// it == btlNeckStart.end()
			btlNeckStart[heights[i]] = i;
			if (heights[i] > maxRect) {
				maxRect = heights[i];
			}
		}
	}
	return maxRect;
}

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
