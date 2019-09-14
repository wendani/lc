class Solution {
public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		int len = intervals.size();
		sort(intervals.begin(), intervals.end());
		for (int i = 2; i < len; i++) {
			if (intervals[i][0] < intervals[i - 1][1]) {
				return false;
			}
		}
		return true;
	}
};


/*
 * Example 1:
 *
 * Input: [[0,30],[5,10],[15,20]]
 * Output: false
 *
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: true
 */
