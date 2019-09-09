class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		int cnt =0;

		for (const auto &email : emails) {
			size_t found = email.find('@');
			assert(found != string::npos);

			string domain = email.substr(found + 1);

			string localRaw = email.substr(0, found);
			found = localRaw.find('+');
			if (found != string::npos) {
				localRaw.resize(found);
			}
			string local;
			for (const auto &c : localRaw) {
				if (c != '.') {
					local.push_back(c);
				}
			}

			auto it = domainLocals.find(domain);
			if (it != domainLocals.end()) {
				if (!it->second.count(local)) {
					cnt++;
					it->second.insert(local);
				}
			}
			else {
				// it == domainLocals.end()
				domainLocals.emplace(domain, initializer_list<string>{local});
				cnt++;
			}
		}
		return cnt;
	}
private:
	unordered_map<string, unordered_set<string>> domainLocals;
};


/*
 * Example 1:
 *
 * Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 */
