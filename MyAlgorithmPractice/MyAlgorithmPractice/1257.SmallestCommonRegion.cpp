// 같은 부모 찾기..... 쉬움.. 

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
	string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
		unordered_map<string, string> m_father;

		for (auto it : regions) {
			for (int j = 1; j < it.size(); ++j) {
				m_father[it[j]] = it[0];
			}
		}

		// list of fathers of region1
		list<string> r1_fathers;
		string f = region1;
		r1_fathers.push_back(f);
		while (m_father.find(f) != m_father.end()) {
			f = m_father[f];
			r1_fathers.push_back(f);
		}

		// search fathers of region2
		string f2 = region2;
		if (find(r1_fathers.begin(), r1_fathers.end(), f2) != r1_fathers.end()) {
			return f2;
		}
		
		while (m_father.find(f2) != m_father.end()) {
			f2 = m_father[f2];
			if (find(r1_fathers.begin(), r1_fathers.end(), f2) != r1_fathers.end()) {
				return f2;
			}
		};

		return "";
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<string>> regions = { {"Earth", "North America", "South America"},
		{"North America", "United States", "Canada"},
		{"United States", "New York", "Boston"},
		{"Canada", "Ontario", "Quebec"},
		{"South America", "Brazil"} };

	cout << sol.findSmallestRegion(regions, "Quebec", "New York");
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}