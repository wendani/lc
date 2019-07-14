struct Pillar{
	Pillar() {
	}

	Pillar(int h, int s) : height(h), start(s) {
	}

	int height;
	int start;
};

int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);
	int len = heights.size();

	vector<Pillar> pillars;
	int maxRect = 0;
	for (int i = 0; i < len; i++) {
		int pLen = pillars.size();
		int j;
		for (j = pLen - 1; j >= 0; j--) {
			if (pillars[j].height > heights[i]) {
				int rect = (i - pillars[j].start) * pillars[j].height;
				if (rect > maxRect) {
					maxRect = rect;
				}

				pillars[j].height = heights[i];
			}
			else if (pillars[j].height == heights[i]) {
				j++;
				break;
			} else {
				// pillars[j].height < heights[i]
				j += 2;
				break;
			}
		}
		if (j > pLen) {
			pillars.emplace_back(heights[i], i);
		}
		else if (j < pLen) {
			pillars.resize(j);
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
