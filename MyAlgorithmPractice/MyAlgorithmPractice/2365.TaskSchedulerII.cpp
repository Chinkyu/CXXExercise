// simple 
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
	long long taskSchedulerII(vector<int>& tasks, int space) {
		int l = tasks.size();
		unordered_map<int, long long> aday;


		long long day = 1;
		for (int i = 0; i < l; ++i) {
			if (aday[tasks[i]] > day) {
				day = aday[tasks[i]] + 1;  // do this day and next available day
				aday[tasks[i]] = day + space;
			}
			else {
				day++;
				aday[tasks[i]] = day + space;
			}
		}
		return day - 1;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> tasks = { 5, 8, 8, 5 };
	cout << sol.taskSchedulerII(tasks, 2);

	cin >> c;

}