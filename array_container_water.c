int maxArea(int* height, int heightSize) {
	int i, j;
	int lo, hi;
	int maxWater;

	lo = 0;
	hi = heightSize - 1;
	maxWater = (hi - lo) * (height[lo] <= height[hi] ? height[lo] : height[hi]);
	i = lo;
	j = hi;
	while (i < j) {
		int water = -1;
		int hasUpdate = 0;
		if (height[lo] < height[i]) {
			lo = i;
			hasUpdate = 1;
		}
		else if (height[j] > height[hi]) {
			hi = j;
			hasUpdate = 1;
		}

		if (height[lo] <= height[hi]) {
			i++;
			if (hasUpdate) {
				water = (hi - lo) * height[lo];
			}
		}
		else {
			// height[lo] > height[hi]
			j--;
			if (hasUpdate) {
				water = (hi - lo) * height[hi];
			}
		}
		if (hasUpdate && water > maxWater) {
			maxWater = water;
		}
	}

	return maxWater;
}




int maxArea(int* height, int heightSize) {
	int i, j;
	int max_water;

	max_water = 0;
	for (i = 0; i < heightSize - 1; i++) {
		int lbound = height[i] * (heightSize - i);

		for (j = heightSize - 1; j > i; j--) {
			lbound -= height[i];

			if (lbound <= max_water) {
				break;
			}

			if (height[i] <= height[j]) {
				max_water = lbound;
			}
			else {
				// height[i] > height[j]
				int bound = height[j] * (j - i);
				if (bound > max_water) {
					max_water = bound;
				}
			}
		}
	}

	return max_water;
}
