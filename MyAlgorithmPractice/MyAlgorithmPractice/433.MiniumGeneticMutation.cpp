#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAX_GENE 8

class Solution {
public:
	unordered_map <string, list<string>> m;
	unordered_map<string, int> w;
	int isFind = false;
	int maxDepth = INT_MAX;

	bool isOneMutation(string s1, string s2) {
		int diff = 0;
		for (int i = 0; i < MAX_GENE; ++i) {
			if (s1[i] != s2[i]) diff++;
			if (diff > 1) return false;
		}

		if (diff == 1) {
			return true;
		}
		return false;
	}

	void dfs(string s, string e, int d) {
		if (s.compare(e) == 0) {
			//isFind = true;
			if (d < maxDepth) maxDepth = d;
		}
				
		if (w[s] <= d) return;

		w[s] = d;
		for (auto it : m[s]) {
			dfs(it, e, d + 1);
		}
	}

	int minMutation(string start, string end, vector<string>& bank) {

		list<string> l;
		int sz = bank.size();

		for (auto it : bank) {
			if (isOneMutation(start, it)) l.push_back(it);
		}
		m[start] = l;

		for (int i = 0; i < sz; ++i) {
			l.clear();
			for (int j = 0; j < sz; ++j) {
				if (i == j) continue;
				if (isOneMutation(bank[i], bank[j])) l.push_back(bank[j]);
			}
			m[bank[i]] = l;
		}

		// reset weight 
		w[start] = INT_MAX;
		for (auto it : bank) {
			w[it] = INT_MAX;
		}

		// DFS traverse.. 
		dfs(start, end, 0);

		if (maxDepth == INT_MAX) maxDepth = -1;
		return maxDepth;
	}
};

int main() {
	char c;
	string start = "AACCGGTT";
	string end = "AAACGGTA";
	vector<string> bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };

	Solution sol;

	cout << sol.minMutation(start, end, bank);

	cin >> c;
}
