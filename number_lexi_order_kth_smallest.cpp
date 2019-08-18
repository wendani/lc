class Solution {
public:
	int findKthNumber(int n, int k) {
		if (n < k) {
			return -1;
		}

		int dist = k - 1;
		uint64_t num = 1;
		while (dist) {
			int d = distToCurrPlusOne(n, num);
			if (d <= dist) {
				num++;
				dist -= d;
			}
			else {
				// d > dist
				num *= 10;
				dist--;
			}
		}

		return num;
	}
private:
	int distToCurrPlusOne(const int &n, uint64_t curr)
	{
		int cnt = 0;

		uint64_t next = curr + 1;
		while (next < n) {
			cnt += (next - curr);
			next *= 10;
			curr *= 10;
		}

		if (curr <= n) {
			cnt += (n - curr);
			if (n < next) {
				cnt++;
			}
		}

		return cnt;
	}
};

class Solution {
public:
	int findKthNumber(int n, int k) {
		if (n < k) {
			return -1;
		}

		priority_queue<string, vector<string>, comp> maxPriQ;

		int i;
		for (i = 1; i <= k; i++) {
			maxPriQ.push(to_string(i));
		}
		for (; i <= n; i++) {
			const auto &sTop = maxPriQ.top();
			string &&s = to_string(i);
			if (s < sTop) {
				maxPriQ.pop();
				maxPriQ.push(s);
			}
		}
		return stoi(maxPriQ.top());
	}
private:
	struct comp {
		bool operator()(const string &a, const string &b)
		{
			return a < b ? true : false;
		}
	};
};

	struct comp {
		bool operator()(const string &a, const string &b)
		{
			int len = a.length();
			if (b.length() < a.length) {
				len = b.length();
			}

			for (int i = 0; i < len; i++) {
				if (a[i] < b[i]) {
					return true;
				}
				else if (a[i] > b[i]) {
					return false;
				}
			}
			return a.length() < b.length() ? true : false;
		}
	}

/*
 * Example:
 *
 * Input:
 * n: 13   k: 2
 *
 * Output:
 * 10
 *
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
 */
