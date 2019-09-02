class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int> alphaIdx;

		int idx = 0;
		for (const auto &alpha : order) {
			alphaIdx.emplace(alpha, idx);
			idx++;
		}

		int len = words.size();
		if (len < 1) {
			return true;
		}

		for (int i = 1; i < len; i++) {
			const string &wordA = words[i - 1];
			const string &wordB = words[i];
			int lenA = wordA.length();
			int lenB = wordB.length();

			for (int j = 0; j < lenA && j < lenB; j++) {
				if (alphaIdx[wordA[j]] > alphaIdx[wordB[j]]) {
					return false;
				}
			}
			if (lenA > lenB) {
				return false;
			}
		}
		return true;
	}
};


/*
 * Example 1:
 *
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
 *
 * Example 2:
 *
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
 *
 * Example 3:
 *
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string is shorter (in size).
 * According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 */


