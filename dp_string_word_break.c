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
	bool *canBreak;

	if (!s)
		return false;

	len = strlen(s);
	canBreak = (bool *)malloc((len + 1) * sizeof(bool));

	canBreak[0] = true;
	for (i = 1; i <= len; i++) {
		canBreak[i] = false;

		for (j = 0; j < i; j++) {
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

	return canBreak[len];
}
