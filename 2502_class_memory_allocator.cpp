class Allocator {
public:
    Allocator(int n) {
        m_size = n;
        m_idxSizes.emplace(n, 0);
    }

    int allocate(int size, int mID) {
        int idx = 0;

        for (const auto &p : m_idxSizes)
        {
            if (p.first - idx >= size)
            {
                // Block found
                break;
            }

            idx = p.first + p.second;
        }

        if (idx >= m_size)
        {
            return -1;
        }

        m_idxSizes.emplace(idx, size);
        m_mIdIndices[mID].push_back(idx);
        return idx;
    }

    int freeMemory(int mID) {
        int size = 0;

        if (!m_mIdIndices.count(mID))
        {
            return size;
        }

        for (const auto &idx : m_mIdIndices[mID])
        {
            size += m_idxSizes[idx];
            m_idxSizes.erase(idx);
        }
        m_mIdIndices.erase(mID);

        return size;
    }

private:
    int m_size;

    set<int, int> m_idxSizes;
    set<int, vector<int>> m_mIdIndices;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
