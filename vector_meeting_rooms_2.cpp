class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<vector<int>> timePoints;

		for (const auto &interval : intervals) {
			// start time, indicated by 1 as the second element
			timePoints.emplace_back(initializer_list<int>{interval[0], 1});
			// end time, indicated by 0 as the second element
			// if start time == end time, end time will always come first
			timePoints.emplace_back(initializer_list<int>{interval[1], 0});
		}

		sort(timePoints.begin(), timePoints.end());

		int min = 0;
		int cnt = 0;
		for (const auto &timePoint : timePoints) {
			if (timePoint[1] == 0) {
				cnt--;
			}
			if (timePoint[1] == 1) {
				cnt++;
				if (cnt > min) {
					min = cnt;
				}
			}
		}
		return min;
	}
};

/*
 * Example 1:
 *
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 *
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: 1
 */
