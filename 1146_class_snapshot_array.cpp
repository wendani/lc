class SnapshotArray {
public:
    SnapshotArray(int length) {
        m_valSnapshots.clear();
        m_valSnapshots.resize(length);

        m_snap_id = 0;

        for (int idx = 0; idx < length; idx++)
        {
            m_valSnapshots[idx].emplace_back(m_snap_id, 0);
        }
    }

    void set(int index, int val) {
        vector<SnapVal> &snapVals = m_valSnapshots[index];
        if (snapVals.back().first == m_snap_id)
        {
            snapVals.back().second = val;
        }
        else
        {
            snapVals.emplace_back(m_snap_id, val);
        }
    }

    int snap() {
        return m_snap_id++;
    }

    int get(int index, int snap_id) {
        const vector<SnapVal> &snapVals = m_valSnapshots[index];

        int idxLow = 0;
        int idxHigh = snapVals.size() - 1;
        while (idxLow <= idxHigh)
        {
            int idxMid = (idxLow + idxHigh) >> 1;

            if (snap_id < snapVals[idxMid].first)
            {
                idxHigh = idxMid - 1;
            }
            else if (snap_id > snapVals[idxMid].first)
            {
                idxLow = idxMid + 1;
            }
            else
            {
                // snap_id == snapVals[idxMid].first
                return snapVals[idxMid].second;
            }
        }

        return snapVals[idxHigh].second;
    }

private:
    typedef pair<int, int> SnapVal;
    vector<vector<SnapVal>> m_valSnapshots;

    int m_snap_id;
};

// Time Limit Exceeded 70/78
class SnapshotArray {
public:
    SnapshotArray(int length) {
        currVals.clear();
        currVals.resize(length);

        m_valSnapshots.clear();
        m_valSnapshots.resize(length);

        m_snap_id = 0;
    }

    void set(int index, int val) {
        currVals[index] = val;
    }

    int snap() {
        for (int idx = 0; idx < currVals.size(); idx++)
        {
            vector<SnapVal> &snapVals = m_valSnapshots[idx];
            if (snapVals.empty())
            {
                snapVals.emplace_back(m_snap_id, currVals[idx]);
            }
            else
            {
                // Record change only
                if (snapVals.back().second != currVals[idx])
                {
                    snapVals.emplace_back(m_snap_id, currVals[idx]);
                }
            }
        }

        return m_snap_id++;
    }

    // Binary search
    int get(int index, int snap_id) {
        vector<SnapVal> &snapVals = m_valSnapshots[index];

        int idxLow = 0;
        int idxHigh = snapVals.size() - 1;
        while (idxLow <= idxHigh)
        {
            int idxMid = (idxLow + idxHigh) >> 1;

            if (snap_id < snapVals[idxMid].first)
            {
                idxHigh = idxMid - 1;
            }
            else if (snap_id > snapVals[idxMid].first)
            {
                idxLow = idxMid + 1;
            }
            else
            {
                // snap_id == snapVals[idxMid].first
                return snapVals[idxMid].second;
            }
        }

        return snapVals[idxHigh].second;
    }

private:
    vector<int> currVals;

    typedef pair<int, int> SnapVal;
    vector<vector<SnapVal>> m_valSnapshots;

    int m_snap_id;
};

// Memory Limit Exceeded 68/78
class SnapshotArray {
public:
    SnapshotArray(int length) {
        currVals.clear();
        currVals.resize(length);

        m_valSnapshots.clear();
        m_valSnapshots.resize(length);

        m_snap_id = 0;
    }

    void set(int index, int val) {
        currVals[index] = val;
    }

    int snap() {
        for (int idx = 0; idx < currVals.size(); idx++)
        {
            m_valSnapshots[idx][m_snap_id] = currVals[idx];
        }

        return m_snap_id++;
    }

    int get(int index, int snap_id) {
        return m_valSnapshots[index][snap_id];
    }

private:
    vector<int> currVals;

    vector<unordered_map<int, int>> m_valSnapshots;

    int m_snap_id;
};

/*
 * 1146. Snapshot Array
 *
 * Implement a SnapshotArray that supports the following interface:
 *
 * SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
 * void set(index, val) sets the element at the given index to be equal to val.
 * int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
 * int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 *
 *
 * Example 1:
 *
 * Input: ["SnapshotArray","set","snap","set","get"]
 * [[3],[0,5],[],[0,6],[0,0]]
 * Output: [null,null,0,null,5]
 * Explanation:
 * SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
 * snapshotArr.set(0,5);  // Set array[0] = 5
 * snapshotArr.snap();  // Take a snapshot, return snap_id = 0
 * snapshotArr.set(0,6);
 * snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
 *
 *
 * Constraints:
 *
 * 1 <= length <= 5 * 104
 * 0 <= index < length
 * 0 <= val <= 109
 * 0 <= snap_id < (the total number of times we call snap())
 * At most 5 * 104 calls will be made to set, snap, and get.
 */
