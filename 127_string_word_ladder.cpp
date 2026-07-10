int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordSet;
	for (const auto &w : wordList) {
		wordSet.insert(w);
	}

	vector<unordered_set<string>> s(2);
	unordered_set<string> searched;

	unordered_set<string> *curr = &s[0];
	unordered_set<string> *next = &s[1];

	int length = 0;
	curr->insert(beginWord);
	while (!curr->empty()) {
		length++;

		for (const auto &word : *curr) {
			if (word == endWord)
				return length;

			int wLen = word.length();
			for (int i = 0; i < wLen; i++) {
				string w = word;

				for (char newc = 'a'; newc <= 'z'; newc++) {
					if (w[i] == newc) {
						continue;
					}

					w[i] = newc;
					if (wordSet.count(w) && !searched.count(w)) {
						next->insert(w);
						searched.insert(w);
					}
				}
			}
		}
		curr->clear();

		auto *temp = curr;
		curr = next;
		next = temp;
	}

	return 0;
}

bool isDiffByOne(const string &a, const string &b)
{
	if (a.length() != b.length()) {
		return false;
	}

	int diff = 0;
	auto it_a = a.begin();
	auto it_b = b.begin();
	while (it_a != a.end()) {
		if (*it_a != *it_b) {
			diff++;
			if (diff > 1) {
				return false;
			}
		}

		it_a++;
		it_b++;
	}

	if (!diff) {
		return false;
	}

	return true;
}
