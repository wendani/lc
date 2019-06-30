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
	vector<queue<string>> q(2);
	unordered_set<string> touched;

	queue<string> *curr = &q[0];
	queue<string> *next = &q[1];

	int length = 0;
	next->push(beginWord);
	while (!next->empty()) {
		auto *temp = curr;
		curr = next;
		next = temp;

		length++;

		while (!curr->empty()) {
			string &word = curr->front();

			if (word == endWord)
				return length;


			for (const auto &w : wordList) {
				if (touched.count(w)) {
					continue;
				}

				if (isDiffByOne(word, w)) {
					next->push(w);
					touched.insert(w);
				}
			}

			curr->pop();
		}
	}

	return 0;
}
