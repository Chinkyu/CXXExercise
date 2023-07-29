// 리커시브로 돌리면서 미모이제이션을 해야 되는데.. memoization 은  x,y,z,last 로 
// map으로 하면 timeout나서.. 배열로 해야됨.. 
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
#include <cmath>

using namespace std;

// add memoization  (num + last 로 만들어야 한다) -> timeout 
// x-0, y-1, z-2
// graph 
// x-y, y- x,z, z-x,z
class Solution {
public:
	int dp[51][51][51][8];

	int dfs(vector<int> &num, vector<int> &seq, map<vector<int>, int> & m) {
		int l = seq.size();
		int last = 4;
		if (l > 0) last = seq[l - 1];
		int tmax = 0;

		// for map index
		//vector<int> tnum = num;
		//tnum.push_back(last);

		if (dp[num[0]][num[1]][num[2]][last] != -1) return dp[num[0]][num[1]][num[2]][last];

		switch (last) {
		case 0:  // x(0)-y(1)
			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[1]++;
				seq.pop_back();
			}
			else {
				return 0;
			}
			break;
		case 1:  // y(1) - x(0), z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}

			break;
		case 2: // z(2) - x(0),z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}
			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}
			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}
			break;
		default:
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[1]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[1] == 0 & num[2] == 0) {
				return 0;
			}
			break;
		}

		dp[num[0]][num[1]][num[2]][last] = tmax; //  max(m[seq], tmax);
		//m[num] = max(m[num], tmax);
		return tmax;
	}


	int longestString(int x, int y, int z) {
		vector<int> num = { x, y, z };
		vector<int> seq;
		map<vector<int>, int> m;

		memset(dp, -1, sizeof(dp));

		return dfs(num, seq, m);
	}
};



// add memoization  (num + last 로 만들어야 한다) -> timeout 
// x-0, y-1, z-2
// graph 
// x-y, y- x,z, z-x,z
class __Solution {
public:

	int dfs(vector<int> &num, vector<int> &seq, map<vector<int>, int> & m) {
		int l = seq.size();
		int last = -1;
		if (l > 0) last = seq[l - 1];
		int tmax = 0;
		
		// for map index
		vector<int> tnum = num;
		tnum.push_back(last);

		if (m.find(tnum) != m.end()) return m[tnum];

		switch (last) {
		case 0:  // x(0)-y(1)
			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[1]++;
				seq.pop_back();
			}
			else {
				return 0;
			}
			break;
		case 1:  // y(1) - x(0), z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}

			break;
		case 2: // z(2) - x(0),z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}
			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}
			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}
			break;
		default:
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[1]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq, m) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[1] == 0 & num[2] == 0) {
				return 0;
			}
			break;
		}

		m[tnum] = tmax; //  max(m[seq], tmax);
		//m[num] = max(m[num], tmax);
		return tmax;
	}


	int longestString(int x, int y, int z) {
		vector<int> num = { x, y, z };
		vector<int> seq;
		map<vector<int>, int> m;

		return dfs(num, seq, m);
	}
};



// timeout 

// x-0, y-1, z-2
// graph 
// x-y, y- x,z, z-x,z
class _Solution {
public:

	int dfs(vector<int> &num, vector<int> &seq) {
		int l = seq.size();
		int last = -1; 
		if (l > 0) last = seq[l - 1];
		int tmax = 0;

		switch (last) {
		case 0:  // x(0)-y(1)
			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[1]++;
				seq.pop_back();
			}
			else {
				return 0;
			}
			break;
		case 1:  // y(1) - x(0), z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}

			break;
		case 2: // z(2) - x(0),z(2)
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[0]++;
				seq.pop_back();
			}
			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[2]++;
				seq.pop_back();
			}
			if (num[0] == 0 && num[2] == 0) {
				return 0;
			}
			break;
		default:
			if (num[0] > 0) {
				seq.push_back(0);
				num[0]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[0]++;
				seq.pop_back();
			}

			if (num[1] > 0) {
				seq.push_back(1);
				num[1]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[1]++;
				seq.pop_back();
			}

			if (num[2] > 0) {
				seq.push_back(2);
				num[2]--;
				tmax = max(tmax, dfs(num, seq) + 2);
				num[2]++;
				seq.pop_back();
			}

			if (num[0] == 0 && num[1] == 0 & num[2] == 0) {
				return 0;
			}
			break;
		}

		return tmax;
	}


	int longestString(int x, int y, int z) {
		vector<int> num = { x, y, z };
		vector<int> seq;

		return dfs(num, seq);
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.longestString(2, 5, 1);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
