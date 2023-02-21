//  Easily accepted 
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

//	// compare function for send pair
//	static bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
//		return (a.second > b.second);
//	}

	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<pair<int, int>> track;
		for (auto it : trips) {
			track.push_back(pair<int, int>(it[1], it[0]));
			track.push_back(pair<int, int>(it[2], -it[0]));
		}

		// sort
		sort(track.begin(), track.end());

		int prv = track[0].first;
		int c = 0;
		for (auto it : track) {
			if (prv != it.first) {
				// check c if larger than capacity
				if (c > capacity) return false;
			}
			c += it.second;

		}

		return true;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> t = { {2, 1, 5},{3, 3, 7} };

	cout << sol.carPooling(t, 4) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}