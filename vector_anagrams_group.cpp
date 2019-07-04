vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, int> signatures;
	vector<vector<string>> results;

	int curr_idx = 0;
	for (const atuo &str : strs) {
		string s = str;
		sort(s.begin(), s.end());

		auto it = signatures.find(s);
		if (it != signatures.end()) {
			results[it->second].push_back(str);
		}
		else {
			// it == signatures.end()
			signatures[s] = curr_idx;
			results[curr_idx].push_back(str);
			curr_idx++;
		}
	}

	return results;
}
