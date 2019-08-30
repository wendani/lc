class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.length() - 1;
		int j = b.length() - 1;
		int credit = 0;
		string c;
		for (; i >= 0 && j >= 0; i--, j--) {
			int sum = 0;
			sum += (a[i] - '0');
			sum += (b[j] - '0');
			sum += credit;

			credit = sum & 0x2 ? 1 : 0;

			c.insert(0, 1, (sum & 0x1) + '0');
		}

		for (; i >= 0; i--) {
			int sum = 0;
			sum += (a[i] - '0');
			sum += credit;

			credit = sum & 0x2 ? 1 : 0;

			c.insert(0, 1, (sum & 0x1) + '0');
		}

		for (; j >= 0; j--) {
			int sum = 0;
			sum += (b[j] - '0');
			sum += credit;

			credit = sum & 0x2 ? 1 : 0;

			c.insert(0, 1, (sum & 0x1) + '0');
		}

		if (credit) {
			c.insert(0, 1, '1');
		}

		return c;
	}
};

/*
 * Example 1:
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */
