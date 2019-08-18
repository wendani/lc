/*
 * Example 1:
 *
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 * Example 2:
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 * Example 3:
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 */


class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> combiNum(amount + 1, 0);

		int len = coins.size();
		combiNum[0] = 1;
		for (int i = 0; i < len; i++) {
			for (int amnt = coins[i]; amnt <= amount; amnt++) {
				combiNum[amnt] += combiNum[amnt - coins[i]];
			}
		}
		return combiNum[amount];
	}
};
