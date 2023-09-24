//  쉽게 해결됨... 
// merge sort 를 의도 한것 같으나.. 그냥 해도 됨.. 

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
	int matrixMedian(vector<vector<int>>& grid) {
		long long sum = 0;
		vector<int> v;

		for (auto it : grid) {
			for (auto jt : it) {
				v.push_back(jt);
			}
		}

		sort(v.begin(), v.end());
		int l = v.size();
		return v[l / 2];
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> garbage = { "G", "P", "GP", "GG" };
	vector<int> travel = { 2, 4, 3 };

	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}