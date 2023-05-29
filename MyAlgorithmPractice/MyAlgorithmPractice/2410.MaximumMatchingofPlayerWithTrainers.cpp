//  어이없게..  풀림... 

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
	int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
		map<int, bool> p, t;

		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end());

		int i = 0, j = 0, ans = 0;

		while (i < players.size() && j < trainers.size()) {
			if (players[i] <= trainers[j]) {
				ans++;
				j++;
				i++;
			}
			else {
				j++;
			}
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "AAAAAAAAAAA"; //  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"; //  "011010";
	vector<string> v = sol.findRepeatedDnaSequences(s);

	for (auto it : v) {
		cout << it << endl;
	}

	cin >> c;
}