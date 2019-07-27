/*
 * Example:
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 */


class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		cap = size;
		vals.resize(cap, 0);
	}

	double next(int val) {
		sum -= vals[pos];
		sum += val;
		vals[pos] = val;

		if (siz < cap) {
			siz++;
		}

		pos++;
		if (pos == cap) {
			pos = 0;
		}

		return static_cast<double>(sum) / siz;
	}

private:
	int cap;
	vector<int> vals;

	int siz = 0;

	int pos = 0;
	int sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
