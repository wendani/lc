class Solution {
public:
	string getHint(string secret, string guess) {
		int len = secret.length();

		assert(len == guess.length());

		int secretDigiCounts[DIGINUM] = {0};
		int guessDigiCounts[DIGINUM] = {0};
		int bulls = 0;
		for (int i = 0; i < len; i++) {
			secretDigiCounts[secret[i] - '0']++;
			guessDigiCounts[guess[i] - '0']++;

			if (secret[i] == guess[i]) {
				bulls++;
			}
		}

		int cows = 0;
		for (int i = 0; i < DIGINUM; i++) {
			cows += min(secretDigiCounts[i], guessDigiCounts[i]);
		}
		cows -= bulls;

		stringstream hint;
		hint << bulls << "A" << cows << "B";
		return hint.str();
	}
private:
	static const int DIGINUM = 10;
};


/*
 * Example 1:
 *
 * Input: secret = "1807", guess = "7810"
 *
 * Output: "1A3B"
 *
 * Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
 *
 * Example 2:
 *
 * Input: secret = "1123", guess = "0111"
 *
 * Output: "1A1B"
 *
 * Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
 */
