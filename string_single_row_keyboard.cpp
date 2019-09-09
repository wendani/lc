class Solution {
public:
	int calculateTime(string keyboard, string word) {
		int charIdx[CHAR_NUM];

		int len = keyboard.length();
		assert(len == CHAR_NUM);

		for (int i = 0; i < len; i++) {
			charIdx[keyboard[i] - 'a'] = i;
		}

		int prevIdx = 0;
		int time = 0;
		for (const auto &c : word) {
			int &currIdx = charIdx[c - 'a'];
			time += abs(currIdx - prevIdx);
			prevIdx = currIdx;
		}
		return time;
	}
private:
	static const int CHAR_NUM = 26;
};


/*
 * Example 1:
 *
 * Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
 * Output: 4
 * Explanation: The index moves from 0 to 2 to write 'c' then to 1 to write 'b' then to 0 again to write 'a'.
 * Total time = 2 + 1 + 1 = 4.
 *
 * Example 2:
 *
 * Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
 * Output: 73
 */
