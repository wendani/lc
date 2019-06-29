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

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	queue<string> toTransform;
	unordered_set<string> transformed;

	int length = 0;
	toTransform.push(beginWord);
	while (!toTransform.empty()) {
		string &word = toTransform.front();

		if (word == endWord)
			return length;

		length++;
		transformed.insert(word);

		for (const auto &w : wordList) {
			if (transformed.count(w)) {
				continue;
			}

			if (isDiffByOne(word, w)) {
				toTransform.push(w);
			}
		}

		toTransform.pop();
	}

	return 0;
}
