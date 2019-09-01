// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Number of characters to read
	 * @return    The number of actual characters read
	 */
	int read(char *buf, int n) {
		if (!buf || n < 1) {
			return 0;
		}

		int rem = n;
		while (rem >= 4) {
			int numRead = read4(buf);
			rem -= numRead;
			buf += numRead;
			if (numRead < 4) {
				return n - rem;
			}
		}

		if (rem > 0) {
			// rem < 4
			char temp[4];
			int numRead = read4(temp);
			if (numRead > rem) {
				numRead = rem;
			}
			memcpy(buf, temp, numRead);
			rem -= numRead;
		}
		return n - rem;
	}
};


/*
 * Definition of read4:
 *
 *     Parameter:  char[] buf
 *     Returns:    int
 *
 * Note: buf[] is destination not source, the results from read4 will be copied to buf[]
 *
 * Below is a high level example of how read4 works:
 *
 * File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
 * char[] buf = new char[4]; // Create buffer with enough space to store characters
 * read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
 * read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
 * read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
 */
