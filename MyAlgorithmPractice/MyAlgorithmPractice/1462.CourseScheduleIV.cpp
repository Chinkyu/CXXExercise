// 타임아웃나서 답 봤음...알고리즘 사용해야함...  skip

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


// timeout .. 
class Solution {
public:

	bool isprerequisit(int s, int p, map<int, list<int>> &m) {
		queue<int> q;

		q.push(s);

		while (q.size() != 0) {
			int f = q.front();
			q.pop();

			if (m.find(f) != m.end()) {
				for (auto it : m[f]) {
					if (it == p) return true;
					q.push(it);
				}
			}
		}
		return false;
	}


	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		map<int, list<int>> m;
		vector<bool> ans;

		for (auto it : prerequisites) {
			m[it[0]].push_back(it[1]);
		}

		for (auto it : queries) {
			ans.push_back(isprerequisit(it[0], it[1], m));
		}

		return ans;
	}
};



int main() {
	char c;
	Solution sol;

	string s = "00110110";
	cout << sol.hasAllCodes(s, 2);

	cin >> c;
}