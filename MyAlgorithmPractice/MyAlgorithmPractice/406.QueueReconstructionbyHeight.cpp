#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		auto comp = [](const vector<int>& p1, const vector<int>& p2) {
			return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); 
		};
		sort(people.begin(), people.end(), comp);
		vector<vector<int>> res;
		for (auto& p : people)
			res.insert(res.begin() + p[1], p);
		return res;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> in = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

	vector<vector<int>> out = sol.reconstructQueue(in);

	for (auto it : out) {
		cout << it[0] << " " << it[1] << endl;
	}
	cout << endl;
	for (auto it : in) {
		cout << it[0] << " " << it[1] << endl;
	}

	cin >> c;
}