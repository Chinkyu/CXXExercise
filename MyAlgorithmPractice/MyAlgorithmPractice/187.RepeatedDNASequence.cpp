#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		int len = s.size();
		unordered_map<string, int> um;
		vector<string> ans;

		for (int i = 0; i <= len - 10; ++i) {
			string ss = s.substr(i, 10);

			if (um.find(ss) != um.end()) {
				um[ss]++;
			}
			else {
				um[ss] = 1;
			}
		}

		for (auto it : um) {
			if (it.second >= 2) ans.push_back(it.first);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	//string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string s = "AAAAAAAAAAA";

	vector<string> vs = sol.findRepeatedDnaSequences(s);

	for (auto it : vs) {
		cout << it << " ";
	}

	cin >> c;
}
