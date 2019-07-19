vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> mergedIntervals;

	int len = intervals.size();
	if (!len) {
		return mergedIntervals;
	}

	sort(intervals.begin(), intervals.end());

	// reach here when intervals has at least one interval
	int i = 0;
	int close = intervals[i][1];
	for (int j = i + 1; j < len; j++) {
		if (close < intervals[j][0]) {
			mergedIntervals.emplace_back(initializer_list<int>{intervals[i][0], close});
			i = j;
			close = intervals[i][1];
		}
		else if (close < intervals[j][1]) {
			close = intervals[j][1];
		}
	}
	mergedIntervals.emplace_back(initializer_list<int>{intervals[i][0], close});
	return mergedIntervals;
}
