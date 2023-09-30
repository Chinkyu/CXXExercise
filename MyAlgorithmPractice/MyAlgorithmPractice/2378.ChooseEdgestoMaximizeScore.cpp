// 문제 말이 안되는  Fail  이 있는데...    skip

/*
nput
edges =
[[-1,-1],[5,551218],[4,866844],[0,828151],[6,17412],[7,-298822],[3,700735],[6,-884559]]
Use Testcase
Output
1694995
Expected
2246213

2246213  ==>  이 값이 나올수가 없는데....


*/





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

class Solution {
public:
	long long maxScore(vector<vector<int>>& edges) {
		vector<vector<int>> myedges;
		int l = edges.size();

		for (int i = 0; i < l; ++i) {
			myedges.push_back({ i, edges[i][0], edges[i][1] });
		}

		sort(myedges.begin(), myedges.end(), [](vector<int> &l, vector<int> &r) {
			return l[2] > r[2];
		});

		int gmax = 0;
		for (int i = 0; i < l; ++i) {
			int lmax = 0;
			for (int j = i + 1; j < l; ++j) {
				set<int> s;
				s.insert(myedges[i][0]);
				s.insert(myedges[i][1]);
				s.insert(myedges[j][0]);
				s.insert(myedges[j][1]);

				if (s.size() == 4) {
					if (myedges[i][2] + myedges[j][2] >= lmax) {
						lmax = myedges[i][2] + myedges[j][2];
					}
					else {
						//break;
					}
				}
			}
			if (lmax >= gmax) {
				gmax = lmax;
			}
			else {
				break;
			}
		}

		if (gmax < myedges[0][2]) gmax = myedges[0][2];
		return gmax;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> edges = {{-1, -1}, {0, 5}, {0, 10}, {2, 6}, {2, 4}};

	cout << sol.maxScore(edges);

	cin >> c;
}