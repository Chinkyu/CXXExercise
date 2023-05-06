// 답 봤음... 잘 이해 안되.. -> 다시 확인 
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
	int numberOfBoomerangs(vector<vector<int>>& points) {
		map<vector<int>, vector<int>>m;
		int cnt = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				if (i != j) {
					int dis = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
					m[points[i]].push_back(dis);
				}
			}
		}
		for (auto it : m) {
			map<int, int>m1;
			for (auto it1 : it.second) { m1[it1]++; }
			for (auto it1 : m1) {
				cnt += it1.second*(it1.second - 1);
			}
		}
		return cnt;
	}
};

// 중복 체크를 해야 하는데 복잡함... !! 
class Solution {
public:
	inline float getDistance(vector<int> &s, vector<int> &e) {
		return sqrt(pow(abs(s[0] - e[0]), 2) + pow(abs(s[1] - e[1]), 2));
	}

	int nCr(int n, int r)
	{
		if (r > n)
			return 0;
		if (r == 0 || r == n)
			return 1;
		return nCr(n - 1, r - 1) + nCr(n - 1, r);
	}

	int numberOfBoomerangs(vector<vector<int>>& points) {
		int l = points.size();
		map<float, int> m;

		for (int i = 0; i < l - 1; ++i) {
			for (int j = i + 1; j < l; ++j) {
				float d = getDistance(points[i], points[j]);
				//int intd = d * 100;
				if (m.find(d) == m.end()) m[d] = 1;
				else m[d]++;
			}
		}

		int ans = 0;
		for (auto it : m) {
			if (it.second >= 2) {
				ans += nCr(it.second, 2);
			}
		}
		return ans * 2;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> points = { {0, 0},{1, 0},{-1, 0},{0, 1},{0, -1} };
	//{ {0, 0}, { 1, 0 }, { 2, 0 } };

	cout << sol.numberOfBoomerangs(points);

	cin >> c;
}