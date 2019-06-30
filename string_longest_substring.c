int inSubstring(char *s, int start, int end, char c)
{
	int i;

	if (!s) {
		return -1;
	}

	for (i = start; i <= end; i++) {
		if (s[i] == c) {
			return i;
		}
	}

	return -1;
}

int lengthOfLongestSubstring(char * s){
	int len, start, end;
	int curr_len, max_len;

	if (!s) {
		return 0;
	}

	len = strlen(s);
	start = 0;
	curr_len = 1;
	max_len = 1;
	end = 1;
	while (end < len) {
		int pos = inSubstring(s, start, end - 1, s[end]);
		if (pos < 0) {
			curr_len++;
			if (curr_len > max_len) {
				max_len = curr_len;
			}
		}
		else {
			// s[end] is duplicate in the substring
			start = pos + 1;
			curr_len = (end - start) + 1;
		}

		end++;
	}

	return max_len;
}
