#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
	unordered_map<string, multiset<string>> um;
	void traverse(string u, vector<string> &ans, int dep, int tot) {
		while (um[u].size()) {
			string v = *um[u].begin();
			um[u].erase(um[u].begin());
			traverse(v, ans, dep + 1, tot);
		}
		ans.push_back(u);
	}
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> ans;
		int l = tickets.size();
		if (l <= 0) return ans;

		for (auto it : tickets) {
			um[it[0]].insert(it[1]);
		}

		traverse("JFK", ans, 1, l);
		reverse(ans.begin(), ans.end());
		return ans;

	}

	vector<string> _findItinerary(vector<vector<string>>& tickets) {
		vector<string> ans;
		int l = tickets.size();
		if (l <= 0) return ans;

		unordered_map<string, set<string>> um;

		for (auto it : tickets) {
			um[it[0]].insert(it[1]);
		}

		string cur = "JFK";
		ans.push_back("JFK");
		do {
			int isItem = false;

			if (um[cur].size() == 0) {
				um.erase(cur);
			}
			else {
				//for (auto it : um[cur]) {
				ans.push_back(*um[cur].begin());
				string nxt = *um[cur].begin();
				um[cur].erase(nxt);

				if (um[cur].size() == 0) {
					um.erase(cur);
				}
				cur = nxt;
				//}
			}
		} while (um.empty() != true);
	//	vector<bool> isUsed(l, false);
	//	ans.push_back("JFK");

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector < vector<string>> it =
			{ {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
	//{ {"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"} };

	vector<string> ans = sol.findItinerary(it);


	for (auto it : ans) {
		cout << it.c_str() << " ";
	}

	cin >> c;
}