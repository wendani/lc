/*
 * Example 1:
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

int maxProduct(int* nums, int numsSize){
	int maxPosProdStartFromNextIdx;
	int minNegProdStartFromNextIdx;
	int maxProd;

	assert(nums);
	assert(numsSize > 0);

	maxProd = nums[numsSize - 1];
	maxPosProdStartFromNextIdx = 1;
	minNegProdStartFromNextIdx = 1;
	if (nums[numsSize - 1] > 0) {
		maxPosProdStartFromNextIdx = nums[numsSize - 1];
	}
	else if (nums[numsSize - 1] < 0) {
		minNegProdStartFromNextIdx = nums[numsSize - 1];
	}
	else {
		// nums[numsSize - 1] == 0
		maxPosProdStartFromNextIdx = 0;
		minNegProdStartFromNextIdx = 0;
	}
	for (int i = numsSize - 2; i >= 0; i--) {
		if (nums[i] > 0) {
			maxPosProdStartFromCurrIdx = nums[i] * maxPosProdStartFromNextIdx;
			if (nums[i] > maxPosProdStartFromCurrIdx) {
				maxPosProdStartFromCurrIdx = nums[i];
			}

			minNegProdStartFromCurrIdx = nums[i] * minNegProdStartFromNextIdx;
		}
		else if (nums[i] < 0) {
			maxPosProdStartFromCurrIdx = nums[i] * minNegProdStartFromNextIdx;

			minNegProdStartFromCurrIdx = nums[i] * maxPosProdStartFromNextIdx;
			if (nums[i] < minNegProdStartFromCurrIdx) {
				minNegProdStartFromCurrIdx = nums[i];
			}
		}
		else {
			// nums[i] == 0
			maxPosProdStartFromCurrIdx = 0;
			minNegProdStartFromCurrIdx = 0;
		}

		if (maxPosProdStartFromCurrIdx > maxProd) {
			maxProd = maxProdStartFromCurrIdx;
		}

		maxPosProdStartFromNextIdx = maxPosProdStartFromCurrIdx;
		minNegProdStartFromNextIdx = minNegProdStartFromCurrIdx;
	}
	return maxProd;
}
