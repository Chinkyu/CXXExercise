// 누가 좋아하고 누가 않좋하고..   vector, map  으로 꼬여 있기는 한데..
// logic은  straight-forward 하다.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		int ans = 0;
		vector<unordered_map<int, int>> pref_m(n, unordered_map<int, int>());

		//build pref map :  who,  pref_idx
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < preferences[i].size(); ++j) {
				pref_m[i][preferences[i][j]] = j;
			}
		}

		// build couple map
		unordered_map<int, int> couple_m;

		for (int i = 0; i < pairs.size(); ++i) {
			couple_m[pairs[i][0]] = pairs[i][1];
			couple_m[pairs[i][1]] = pairs[i][0];
		}


		for (int i = 0; i < n; ++i) {
			// pairs[i][0]
			int me = i;
			int mate = couple_m[i];
			int mate_pre_idx = pref_m[me][mate];

			// check persone better
			for (int j = 0; j < mate_pre_idx; ++j) {
				// his mate's ranking
				int my_more_prefer = preferences[me][j];
				int his_my_pref = pref_m[my_more_prefer][me];
				// he prefer me than his current couple
				if (pref_m[my_more_prefer][couple_m[my_more_prefer]] > his_my_pref) {
					ans++;
					break;
				}
			}
		}

		return ans;

	}
};

class _Solution {
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		int ans = 0;
		vector<unordered_map<int, int>> pref_m(n, unordered_map<int, int>());

		//build pref map :  who,  pref_idx
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < preferences[i].size(); ++j) {
				pref_m[i][preferences[i][j]] = j;
			}
		}

		// build couple map
		unordered_map<int, int> couple_m;

		for (int i = 0; i < pairs.size(); ++i) {
			couple_m[pairs[i][0]] = pairs[i][1];
			couple_m[pairs[i][1]] = pairs[i][0];
		}


		for (int i = 0; i < pairs.size(); ++i) {
			// pairs[i][0]
			int me = pairs[i][0];
			int mate = pairs[i][1];
			int mate_pre_idx = pref_m[me][pairs[i][1]];

			// check persone better
			for (int j = 0; j < mate_pre_idx; ++j) {
				// his mate's ranking
				int my_pref = pref_m[mate][me];
				if (preferences[mate][j] < my_pref) {
					ans++;
					break;
				}
			}

			// pairs[i][1]
			me = pairs[i][1];
			mate = pairs[i][0];
			mate_pre_idx = pref_m[me][pairs[i][1]];

			// check persone better
			for (int j = 0; j < mate_pre_idx; ++j) {
				// his mate's ranking
				int my_pref = pref_m[mate][me];
				if (preferences[mate][j] < my_pref) {
					ans++;
					break;
				}
			}

		}

		return ans;

	}
};

int main() {
	char c;

	Solution sol;

//	vector<vector<int>> preference = { {1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0} };
//	vector<vector<int>> pairs = { {0, 1}, {2, 3} };

//	vector<vector<int>> preference = { {1}, {0} };
//	vector<vector<int>> pairs = { {0, 1}};

	vector<vector<int>> preference = { {1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1} };
	vector<vector<int>> pairs = { {1, 3}, {0, 2} };



	cout << sol.unhappyFriends(4, preference, pairs);

	cin >> c;
}