int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);
	int len = heights.size();

	vector<int> starts;
	int maxRect = 0;
	for (int i = 0; i < len; i++) {
		int sLen = starts.size();
		int j;
		for (j = sLen - 1; j >= 0; j--) {
			if (heights[starts[j]] > heights[i]) {
				int rect = (i - starts[j]) * heights[starts[j]];
				if (rect > maxRect) {
					maxRect = rect;
				}

				heights[starts[j]] = heights[i];
			}
			else if (heights[starts[j]] == heights[i]) {
				j++;
				break;
			} else {
				// heights[starts[j]] < heights[i]
				j += 2;
				break;
			}
		}
		if (j > sLen || sLen == 0) {
			starts.emplace_back(i);
		}
		else if (j < sLen) {
			if (j < 0) {
				j = 1;
			}
			starts.resize(j);
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
