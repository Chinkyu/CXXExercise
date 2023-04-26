// 그룹 합치기가 좀 까다롭지만   foundidx가지고... 해결

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		vector<set<int>> ls;
		string ans;

		for (int i = 0; i < s1.size(); ++i) {
			vector<int> foundIdx;
			for (int j = 0; j < ls.size(); ++j) {
				if (ls[j].find(s1[i]) != ls[j].end()) {
					ls[j].insert(s2[i]); 
					foundIdx.push_back(j);
				}
				else if (ls[j].find(s2[i]) != ls[j].end()) {
					ls[j].insert(s1[i]);
					foundIdx.push_back(j);
				}
			}

			if(foundIdx.size() == 0) {
				set<int> s;
				s.insert(s1[i]);
				s.insert(s2[i]);
				ls.push_back(s);
			}

			if (foundIdx.size() == 2 && foundIdx[0] != foundIdx[1]) {
				for (auto it : ls[foundIdx[1]]) {
					ls[foundIdx[0]].insert(it);
				}
				ls.erase(ls.begin() + foundIdx[1]);
			}

		}

		vector<char> ch_conv(26, 0);

		for (auto it : ls) {
			char min = 'z' + 1;
			// find low
			for (auto jt : it) {
				if (jt < min) min = jt;
			}

			// make conversion table
			for (auto jt : it) ch_conv[jt - 'a'] = min;
		}

		for (auto it : baseStr) {
			if (ch_conv[it - 'a'] != 0) {
				ans.push_back(ch_conv[it - 'a']);
			}
			else {
				ans.push_back(it);
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	cout << sol.smallestEquivalentString("parker", "morris", "parser");
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}