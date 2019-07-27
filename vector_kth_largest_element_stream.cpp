/*
 * Example:
 *
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
*/


class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) : kap(k) {
		int i = 0;
		int len = nums.size();
		for (; i < len; i++) {
			if (i < kap) {
				minPriQ.push(nums[i]);
			}
			else if (minPriQ.top() < nums[i]) {
				minPriQ.pop();
				minPriQ.push(nums[i]);
			}
		}
	}

	int add(int val) {
		if (minPriQ.size() < kap) {
			minPriQ.push(val);
		}
		else if (minPriQ.top() < val) {
			minPriQ.pop();
			minPriQ.push(val);
		}
		return minPriQ.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> minPriQ;
	int kap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
