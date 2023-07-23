//  답 봤음... primenumber찾는것부터 ...  그것 이후는 set으로 조합 찾아서 리턴
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

class Solution {
public:
	vector<vector<int>> findPrimePairs(int n) {
		// find prime
		vector<bool> prime(n + 1, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i <= n; ++i) {
			if (prime[i] && (long long)i * i <= n) {
				for (int j = i * i; j <= n; j += i) prime[j] = false;
			}
		}

		// make set
		set<int> st;
		for (int i = 2; i < n + 1; ++i) {
			if (prime[i]) st.insert(i);
		}

		map<int, int> mp;
		for (auto it : st) {
			int res = n - it;
			if (mp.find(res) != mp.end()) continue;
			if (st.find(res) != st.end())  mp[it] = res;
		}

		vector<vector<int>> ans;
		for (auto it : mp) {
			ans.push_back({ it.first, it.second });
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> nodes = { {0, -1}, {1, 0}, {2, 0}, {3, 1}, {4, 1} };

	cout << sol.isPreorder(nodes);

	cin >> c;
}
