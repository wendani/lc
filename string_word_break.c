bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	int i;
	size_t len = strlen(s);

	for (i = 1; i <= len; i++)
		for (j = 0; j < wordDictSize; j++)
			if (!strncmp(s, wordDict[j], i) &&
			    wordBreak(&s[i], wordDict, wordDictSize))
				printf("%s\n", &s[i]);
				return true;

	return false;
}
