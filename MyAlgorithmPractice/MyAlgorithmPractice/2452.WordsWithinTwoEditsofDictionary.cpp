//  brute force - easy
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
	int getDistance(string &s1, string &s2) {
		int l = s1.size();
		int diff = 0;

		for (int i = 0; i < l; ++i) {
			if (s1[i] != s2[i]) diff++;
		}

		return diff;
	}

	vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
		vector<string> ans;

		for (auto it : queries) {
			int tmin = INT_MAX;
			for (auto jt : dictionary) {
				if (getDistance(it, jt) <= 2) {
					ans.push_back(it);
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
	vector<string> queries = { "word","note","ants","wood" };
	vector<string> dictionary = { "wood","joke","moat" };

	vector<string> ans = sol.twoEditWords(queries, dictionary);

	for (auto it : ans) {
		cout << it << " " << endl;
	}

	cin >> c;
}