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
