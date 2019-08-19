class Solution {
public:
	int calculate(string s) {
		stack<int> numStk;

		int len = s.length();
		int i = 0;
		char op = '+';
		while (i < len) {
			if (isDigit(s[i])) {
				int num = 0;
				while (i < len && isDigit(s[i])) {
					num *= 10;
					num += (s[i] - '0');
					i++;
				}
				if (op == '*') {
					numStk.top() *= num;
				} else if (op == '/') {
					numStk.top() /= num;
				} else if (op == '-') {
					numStk.push(-num);
				}
				else {
					assert(op == '+');
					numStk.push(num);
				}
			}
			else if (s[i] == ' ') {
				i++;
			}
			else {
				op = s[i];
				i++;
			}
		}

		int num = 0;
		while (!numStk.empty()) {
			int &n = numStk.top();
			num += n;

			numStk.pop();
		}
		return num;
	}
private:
	bool isDigit(const char &c)
	{
		if ('0' <= c && c <= '9') {
			return true;
		}
		return false;
	}
};

/*
 * Example 1:
 *
 * Input: "3+2*2"
 * Output: 7
 *
 * Example 2:
 *
 * Input: " 3/2 "
 * Output: 1
 *
 * Example 3:
 *
 * Input: " 3+5 / 2 "
 * Output: 5
 */
