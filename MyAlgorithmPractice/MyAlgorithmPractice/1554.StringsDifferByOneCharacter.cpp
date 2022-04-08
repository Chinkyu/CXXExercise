#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	int getDistance(string s1, string s2) {
		int len = s1.length();
		int cnt = 0;

		for (int i = 0; i < len; ++i) {
			if (s1[i] != s2[i]) cnt++;
		}
		return cnt;
	}


	bool _differByOne(vector<string>& dict) {
		int len = dict[0].length();
		int size = dict.size();

		for (int i = 0; i < size; ++i) {
			for (int j = i+1; j < size; ++j) {
				if (1 == getDistance(dict[i], dict[j])) return true;
			}
		}

		return false;
	}

	bool _fromdescription_differByOne(vector<string>& d) {
		int mod = 1000000007, n = d.size(), m = d[0].size();
		vector<int> hash(n);
		for (auto i = 0; i < n; ++i)
			for (auto j = 0; j < m; ++j)
				hash[i] = (26l * hash[i] + (d[i][j] - 'a')) % mod;
		for (int j = m - 1, mult = 1; j >= 0; --j) {
			unordered_map<int, vector<int>> m;
			for (auto i = 0; i < n; ++i) {
				int h = (mod + hash[i] - (long)mult * (d[i][j] - 'a') % mod) % mod;
				auto it = m.find(h);
				if (it != end(m))
					for (int pi : it->second)
						if (equal(begin(d[i]), begin(d[i]) + j, begin(d[pi]))
							&& equal(begin(d[i]) + j + 1, end(d[i]), begin(d[pi]) + j + 1))
							return true;
				m[h].push_back(i);
			}
			mult = 26l * mult % mod;
		}
		return false;
	}

	bool differByOne(vector<string>& dict) {
		int len = dict[0].length();
		int size = dict.size();

		for (int i = 0; i < len; ++i) {
			unordered_map<string, bool> m;
			for (int j = 0; j < size; ++j) {
				string s = dict[j];
				s[i] = 'a';

				if (m.find(s) != m.end()) {  // exist
					return true;
				}
				m[s] = true;
			}
		}

		return false;
	}


};


int main() {
	char c;
	Solution sol;

	vector<string> d = { "abcd", "cccc", "abyd", "abab" }; 
	//vector<string>d = { "ab", "cd", "yz" };

	bool ans = sol.differByOne(d);

	cout << "ans = " << ans << endl;

	cin >> c;
}