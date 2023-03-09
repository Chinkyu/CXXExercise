// map  하고 queue대신에 array를 사용해서 간단하게 해결 가능함.. 

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

class FirstUnique {
public:
	unordered_map<int, int> m;
	vector<int> q;

	FirstUnique(vector<int>& nums) {
		for (auto it : nums) {
			if (m.find(it) == m.end()) {
				m[it] = 1;
				q.push_back(it);
			}
			else {
				m[it]++;
			}
		}
	}

	int showFirstUnique() {
		for (auto it : q) {
			if (m[it] == 1) return it;
		}
		return -1;
	}

	void add(int value) {
		if (m.find(value) == m.end()) {
			m[value] = 1;
			q.push_back(value);
		}
		else {
			m[value]++;
		}
	}
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
int main() {
	char c;

	Solution sol;

	//	vector<vector<int>> points = { {3, 12}, {-2, 5}, {-4, 1} };
	vector<vector<int>> points = { {0, 0},{2, 2},{3, 10},{5, 2},{7, 0} };

	cout << sol.minCostConnectPoints(points);

	cin >> c;
}