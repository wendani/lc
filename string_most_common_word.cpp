/*
 * Example:
 *
 * Input:
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation:
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"),
 * and that "hit" isn't the answer even though it occurs more because it is banned.
 *
 * 1 <= paragraph.length <= 1000.
 * 0 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation symbols.
 */


class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> banSet;
		for (const auto &bw : banned) {
			banSet.insert(bw);
		}

		unordered_map<string, int> wordCnt;
		string &subParagraph = paragraph;
		int maxCnt = 0;
		string mostCommonWord;

		while (!subParagraph.empty()) {
			size_t pos = subParagraph.find(" ");
			string &&w = subParagraph.substr(0, pos);
			if (pos != string::npos) {
				subParagraph = subParagraph.substr(pos + 1);
			}
			else {
				// pos == string::npos
				subParagraph.clear();
			}

			// process word w
			// remove tailing punctuation symbols
			while (puncSymbols.count(w.back())) {
				w.pop_back();
			}
			// convert to lower case
			for (auto &c : w) {
				c = tolower(c);
			}

			if (banSet.count(w)) {
				continue;
			}

			auto it = wordCnt.find(w);
			if (it != wordCnt.end()) {
				it->second++;
			}
			else {
				// it == wordCnt.end()
				auto p = wordCnt.emplace(w, 1);
				it = p.first;
			}
			if (it->second > maxCnt) {
				maxCnt = it->second;
				mostCommonWord = it->first;
			}
		}
		return mostCommonWord;
	}
private:
	static const unordered_set<char> puncSymbols;
};

const unordered_set<char> Solution::puncSymbols = {"!", "?", "'", ",", ";", "."};
