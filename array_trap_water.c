int trap(int* height, int heightSize){
	int i;
	int sum, total_trap;

	if (!height || heightSize < 1)
		return 0;

	total_trap = 0;
	head = 0;
	tail = heightSize - 1;
	sum = 0;
	for (i = head + 1; i <= tail; i++)
		if (height[head] <= height[i]) {
			head = i;
			total_trap += sum;
			sum = 0;
		}
		else {
			// height[head] > height[i]
			sum += (height[head] - height[i]);
		}

	sum = 0;
	for (i = tail - 1; i >= head; i--)
		if (height[i] >= height[tail]) {
			tail = i;
			total_trap += sum;
			sum = 0;
		}
		else {
			// height[i] < height[tail]
			sum += (height[tail] - height[i]);
		}

	return total_trap;
}
