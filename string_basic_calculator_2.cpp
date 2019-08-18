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

class Solution {
public:
	int calculate(string s) {
		stack<int> numStk;
		stack<char> opStk;

		int len = s.length();
		int i = 0;
		while (i < len) {
			if (isDigit(s[i])) {
				int num = 0;
				while (i < len && isDigit(s[i])) {
					num *= 10;
					num += (s[i] - 48);
					i++;
				}
				numStk.push(num);
			}
			else if (s[i] == '+' || s[i] == '-') {
				opStk.push(s[i]);
				i++;
			}
			else if (s[i] == '*' || s[i] == '/') {
				char &op = s[i];

				i++;
				while (i < len && !isDigit(s[i])) {
					i++;
				}
				assert(i < len);
				int numB = 0;
				while (i < len && isDigit(s[i])) {
					numB *= 10;
					numB += (s[i] - 48);
					i++;
				}

				int &numA = numStk.top();
				if (op == '*') {
					numA *= numB;
				} else {
					// op == '/'
					numA /= numB;
				}
			}
			else {
				i++;
			}
		}

		int num = 0;
		while (!opStk.empty()) {
			int &n = numStk.top();
			if (opStk.top() == '-') {
				num -= n;
			}
			else {
				num += n;
			}

			numStk.pop();
			opStk.pop();
		}
		return num + numStk.top();
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
