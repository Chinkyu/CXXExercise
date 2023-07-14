//	답봤음....  차차 이해.. 
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

// 앞에서 부터 자르는 방법인데.. 이게 답이라니.....
class Solution {
public:
	int minimumPartition(string s, int k) {
		int ans = 0;
		long long t = 0;
		for (auto c : s) {
			long long r = t * 10 + c - '0';
			if (r <= k) t = r;
			else {
				ans++;
				t = 0;
				r = c - '0';
				if (r <= k) t = r;
				else return -1;
			}
		}
		if (t <= k) ans++;
		return ans;
	}
};

// this make timeout.. -> memoization 이 필요함.. 
class _Solution {
public:
	int mGroup = INT_MAX;

	void traverse(string &s, int sIdx, int groupNum, int n, int k) {
		int sl = s.size();

		if (sIdx == sl) {
			mGroup = min(mGroup, groupNum);
			return;
		}

		for (int i = 1; i <= n; ++i) {
			if (sIdx + i <= sl) {
				string ss = s.substr(sIdx, i);
				int si = stoi(ss);
				if (si <= k) {
					traverse(s, sIdx + i, groupNum + 1, n, k);
				}
			}
		}
	}

	int minimumPartition(string s, int k) {
		string ks = to_string(k);
		int n = ks.size();

		mGroup = INT_MAX;
		traverse(s, 0, 0, n, k);

		if (mGroup == INT_MAX) mGroup = -1;
		return mGroup;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "165462";
	cout << sol.minimumPartition(s, 60);
	
	cin >> c;
}
