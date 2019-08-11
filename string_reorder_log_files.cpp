/*
 * The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.
 * The digit-logs should be put in their original order.
 *
 * Return the final order of the logs.
 *
 * Example 1:
 *
 * Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
 * Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 */


static comp(const string &a, const string &b)
{
	size_t aFound = a.find(" ");
	assert(aFound != string::npos);
	const string &&aSub = a.substr(aFound + 1);

	size_t bFound = b.find(" ");
	assert(bFound != string::npos);
	const string &&bSub = b.substr(bFound + 1);

	if (aSub < bSub) {
		return true;
	}
	else if (aSub > bSub) {
		return false;
	}

	// reach here when aSub == bSub
	const string &&aId = a.substr(0, aFound);
	const string &&bId = b.substr(0, aFound);
	if (aId < bId) {
		return true;
	}
	return false;
}

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		int len = logs.size();

		int digitSwapIdx = len - 1;
		for (; digitSwapIdx >= 0 && isDigitLog(logs[digitSwapIdx]); digitSwapIdx--) {
			;
		}

		int curr = digitSwapIdx - 1;
		while (curr >= 0) {
			if (isDigitLog(logs[curr])) {
				string temp = logs[digitSwapIdx];
				logs[digitSwapIdx] = logs[curr];
				logs[curr] = temp;

				digitSwapIdx--;
			}
			curr--;
		}

		sort(logs.begin(), logs.being() + digitSwapIdx, comp);

		return logs;
	}
private:
	bool isDigitLog(const string &log)
	{
		size_t found = log.find(" ");
		assert(found != string::npos);

		char *c = log.substr(found + 1, found + 1).c_str();
		if ('0' <= c[0] && c[0] <= '9') {
			return true;
		}
		return false;
	}
};
