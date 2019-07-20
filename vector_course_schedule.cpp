bool  _dfs(const vector<unordered_set<int> &adjList, vector<bool> &searched, int courseNum)
{
	if (searched[courseNum]) {
		return false;
	}

	searched[courseNum] = true;

	for (const auto &i : adjList[courseNum]) {
		if (!_dfs(adjList, searched, i) {
			return false;
		}
	}

	searched[courseNum] = false;
	return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<unordered_set<int>> adjList(numCourses);
	vector<bool> searched(false, numCourses);

	for (const auto &prerequisite : prerequisites) {
		adjList[prerequisite[1]].insert(prerequisite[0]);
	}

	for (int i = 0; i < numCourses; i++) {
		if (!_dfs(adjList, searched, i)) {
			return false;
		}
	}

	return true;
}
