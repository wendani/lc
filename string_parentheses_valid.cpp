static const unordered_map<char, char> bracketPair;
static const unordered_set<char> openBrackets;

bool isValid(string s) {
	stack<char> cStk;

	for (const auto &c : s) {
		if (openBrackets.count(c)) {
			cStk.push(c);
		}
		else {
			// closing bracket
			if (!cStk.empty()) {
				char oc = cStk.top();
				if (bracketPair.at(oc) != c) {
					return false;
				}
				// reach here when oc == c
				cStk.pop();
			}
			else {
				// cStk is empty; does not contain
				// any open bracket for pairing
				return false;
			}
		}
	}

	return cStk.empty() ? true : false;
}

const unordered_map<char, char> Solution::bracketPair = {
	{'(', ')'},
	{'[', ']'},
	{'{', '}'}
};

const unordered_set<char> Solution::openBrackets = {'(', '[', '{'};
