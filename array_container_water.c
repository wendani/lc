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
