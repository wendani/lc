// Time limit exceeded
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	int i, j;
	size_t len;

	if (!s)
		return false;

	len = strlen(s);
	if (!len)
		return true;

	for (i = 1; i <= len; i++)
		for (j = 0; j < wordDictSize; j++)
			if (strlen(wordDict[j]) == i && !strncmp(s, wordDict[j], i) &&
			    wordBreak(&s[i], wordDict, wordDictSize)) {
				return true;
			}

	return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	size_t len;
	int i, j, k;
	bool *canBreak, final;
	size_t word_len_min, word_len_max;

	if (!s)
		return false;

	if (!wordDict || wordDictSize < 1)
		return false;

	len = strlen(s);
	canBreak = (bool *)malloc((len + 1) * sizeof(bool));

	word_len_min = strlen(wordDict[0]);
	word_len_max = strlen(wordDict[0]);
	for (i = 1; i < wordDictSize; i++) {
		size_t word_len = strlen(wordDict[i]);
		if (word_len_max < word_len) {
			word_len_max = word_len;
		}
		else if (word_len < word_len_min) {
			word_len_min = word_len;
		}
	}

	// canBreak[i] means the first i characters are word breakable
	canBreak[0] = true;
	for (i = 1; i <= len; i++) {
		canBreak[i] = false;

		for (j = i - word_len_min; j >= 0 && j >= i - word_len_max; j--) {
			if (canBreak[i])
				break;

			if (!canBreak[j])
				continue;

			for (k = 0; k < wordDictSize; k++) {
				if (strlen(wordDict[k]) == i - j && !strncmp(&s[j], wordDict[k], i - j)) {
					canBreak[i] = true;
					break;
				}
			}
		}
	}

	final = canBreak[len];
	free(canBreak);
	return final;
}
