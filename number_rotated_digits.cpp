class Solution {
public:
	int rotatedDigits(int N) {
		if (N <= 1) {
			return 0;
		}

		int cnt = 0;
		for (int num = 2; num <= N; num++) {
			bool valid = true;
			int numRotated = 0;
			int factor = 1;
			int i = num;
			while (i) {
				int rem = i % 10;
				rem = rotate[rem];
				if (rem < 0) {
					valid = false;
					break;
				}
				else {
					numRotated += (rem * factor);
				}
				i /= 10;
				factor *= 10;
			}
			if (valid && num != numRotated) {
				cnt++;
			}
		}
		return cnt;
	}
private:
	static const int rotate[10];
};

const int Solution::rotate[10] = {
	 0,
	 1,
	 5,
	-1,
	-1,
	 2,
	 9,
	-1,
	 8,
	 6,
};


class Solution {
public:
	int rotatedDigits(int N) {
		if (N <= 1) {
			return 0;
		}

		int cnt = 0;
		for (int i = 2; i <= N; i++) {
			string s = to_string(i);
			bool valid = true;
			for (auto &c : s) {
				const char &cRotated = rotate[c - '0'];
				if (!cRotated) {
					valid = false;
					break;
				}
				else {
					c = cRotated;
				}
			}
			if (valid) {
				int iRotated = stoi(s);
				if (i != iRotated) {
					cnt++;
				}
			}
		}
		return cnt;
	}
private:
	static const char rotate[10];
};

const char Solution::rotate[10] = {
	'0',
	'1',
	'5',
	 0 ,
	 0 ,
	'2',
	'9',
	 0 ,
	'8',
	'6',
};

/*
 * Example:
 * Input: 10
 * Output: 4
 * Explanation:
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 */
