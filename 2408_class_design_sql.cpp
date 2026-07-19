class SQL {
public:
    SQL(vector<string>& names, vector<int>& columns) {
        const int len = names.size();

        for (int i = 0; i < len; i++)
        {
            m_tblColumnLens.emplace(names[i], columns[i]);
            m_tblRowLens.emplace(names[i], 0);
        }
    }

    bool ins(string name, vector<string> row) {
        if (!m_tblColumnLens.count(name))
        {
            return false;
        }

        // name valid when we reach here
        if (row.size() != m_tblColumnLens[name])
        {
            return false;
        }

        const int rowIdx = ++m_tblRowLens[name];
        m_tables[name].emplace(rowIdx, row);
        return true;
    }

    void rmv(string name, int rowId) {
        if (!m_tblColumnLens.count(name))
        {
            return;
        }

        // name valid when we reach here
        m_tables[name].erase(rowId);
    }

    string sel(string name, int rowId, int columnId) {
        string invalid;

        if (!m_tblColumnLens.count(name))
        {
            return invalid;
        }

        // name valid when we reach here
        if (columnId < 1 || m_tblColumnLens[name] < columnId)
        {
            return invalid;
        }

        // columnId valid when we reach here
        if (!m_tables[name].count(rowId))
        {
            return invalid;
        }

        // row valid when we reach here
        return m_tables[name][rowId][columnId - 1];
    }

    vector<string> exp(string name) {
        vector<string> table;

        if (!m_tblColumnLens.count(name))
        {
            return table;
        }

        // name valid when we reach here
        for (const auto &p : m_tables[name])
        {
            string row{to_string(p.first)};
            for (const auto &cell : p.second)
            {
                row += separator + cell;
            }

            table.push_back(row);
        }

        return table;
    }

private:
    const char separator = ',';
    unordered_map<string, int> m_tblColumnLens;

    unordered_map<string, int> m_tblRowLens;
    unordered_map<string, map<int, vector<string>>> m_tables;
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
