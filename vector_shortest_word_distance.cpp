class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int len = words.size();
		int word1Idx = len;
		int word2Idx = len;
		int minDist = len - 1;
		for (int i = 0; i < len; i++) {
			if (words[i] == word1) {
				word1Idx = i;

				if (word2Idx < len) {
					int dist = abs(word1Idx - word2Idx);
					if (dist < minDist) {
						minDist = dist;
					}
				}
			}
			else if (words[i] == word2) {
				word2Idx = i;

				if (word1Idx < len) {
					int dist = abs(word1Idx - word2Idx);
					if (dist < minDist) {
						minDist = dist;
					}
				}
			}
		}
		return minDist;
	}
};


/*
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 *
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 */
