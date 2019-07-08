vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, int> signatures;
	vector<vector<string>> results;

	int curr_idx = 0;
	for (const auto &str : strs) {
		string s = str;
		sort(s.begin(), s.end());

		auto it = signatures.find(s);
		if (it != signatures.end()) {
			results[it->second].push_back(str);
		}
		else {
			// it == signatures.end()
			results.emplace_back(initializer_list<string>{str});
			signatures[s] = curr_idx;
			curr_idx++;
		}
	}

	return results;
}
