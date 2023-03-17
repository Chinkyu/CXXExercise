//  배렬하고 map  사용하면서  중복 되는경우 해매면서 짰음...
// 색각보다 시간많이 걸리고... 배열도  Bad design....
//  내용이 어렿지는 않은데.. 함정이 있었다고.... 해야 할것 같음.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		unordered_map<string, int> m;
		vector<string> name;

		for (int i = 0; i < accounts.size(); ++i) {
			int found_num = 0;
			set<int> found_idxs;
			// find all email
			for (int j = 1; j < accounts[i].size(); ++j) {
				if (m.find(accounts[i][j]) != m.end()) {
					found_num++;
					found_idxs.insert(m[accounts[i][j]]);
				}
			}

			if (found_num > 0) {
				int idx = *found_idxs.begin();
				for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
					if(found_idxs.find(it->second) != found_idxs.end()) { // Found 
						it->second = idx;
					}
				}

				for (int k = 1; k < accounts[i].size(); ++k) {
					m[accounts[i][k]] = idx;
				}
			}
			else {
				name.push_back(accounts[i][0]);
				for (int k = 1; k < accounts[i].size(); ++k) {
					//if (m.find(accounts[i][k]) != m.end())) 
					m[accounts[i][k]] = name.size() - 1;
				}
			}

		}

		// build answer vector
		vector<vector<string>> ans1, ans2;
		for (int i = 0; i < name.size(); ++i) {
			ans1.push_back({ name[i] });
		}

		for (auto it : m) {
			ans1[it.second].push_back(it.first);
		}

		// remove empty
		for (auto it : ans1) {
			if (it.size() == 1) continue;
			ans2.push_back(it);
		}

		// sort in raw
		for (int i = 0; i < ans2.size(); ++i) {
			sort(ans2[i].begin()+1, ans2[i].end());
		}
		//sort(ans.begin(), ans.end(), [](const vector<string> &l, const vector<string> &r) { return l[0] < r[0]; });

		return ans2;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<string>> accounts = { {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"Aohn", "johnnybravo@mail.com"} };
	vector<vector<string>> accounts = { {"David", "David0@m.co", "David1@m.co"}, { "David", "David3@m.co", "David4@m.co" }, { "David", "David4@m.co", "David5@m.co" }, { "David", "David2@m.co", "David3@m.co" }, { "David", "David1@m.co", "David2@m.co" }};
	vector<vector<string>> ans = sol.accountsMerge(accounts);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << " " << jt;
		}
		cout << endl;
	}

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}