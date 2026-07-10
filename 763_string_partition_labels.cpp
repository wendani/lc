/*
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 */

vector<int> partitionLabels(string S) {
	int len = S.length();

	unordered_map<char, int> charLastIdx;
	int i;
	for (i = 0; i < len; i++) {
		charLastIdx[S[i]] = i;
	}

	vector<int> partitions;
	i = 0;
	int prevLast = -1;
	while (i < len) {
		int currLast = charLastIdx[S[i]];

		while (i < currLast) {
			if (charLastIdx[S[i]] > currLast) {
				currLast = charLastIdx[S[i]];
			}
			i++;
		}

		// reach here when i == currLast
		partitions.push_back(currLast - prevLast);
		prevLast = currLast;
		i++;
	}
	return partitions;
}
