static const unordered_map<string, vector<string>> numLtrsMap;

void _letterCombinations(vector<string> &combinations, const string &digits)
{
	int len = digits.length();

	if (!len) {
		return;
	}

	if (len == 1) {
		for (const auto &ltr : numLtrsMap.at(digits)) {
			combinations.push_back(ltr);
		}
	}

	// reach here when len > 1
	vector<string> subcombinations;
	_letterCombinations(subcombinations, digits.substr(1));
	for (const auto &ltr : numLtrsMap.at(digits.substr(0,1))) {
		for (const auto &subcombination : subcombinations) {
			combinations.push_back(ltr + subcombination);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> combinations;
	_letterCombinations(combinations, digits);
	return combinations;
}

const unordered_map<string, vector<string>> Solution::numLtrsMap = {
	{"1", {}},
	{"2", {"a", "b", "c"}},
	{"3", {"d", "e", "f"}},
	{"4", {"g", "h", "i"}},
	{"5", {"j", "k", "l"}},
	{"6", {"m", "n", "o"}},
	{"7", {"p", "q", "r", "s"}},
	{"8", {"t", "u", "v"}},
	{"9", {"w", "x", "y", "z"}}
};
