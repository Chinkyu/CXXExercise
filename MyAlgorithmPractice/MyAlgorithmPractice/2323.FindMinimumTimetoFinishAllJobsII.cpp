//  답봤고... 어이 없는데... 
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
	int minimumTime(vector<int>& jobs, vector<int>& workers) {
		sort(jobs.begin(), jobs.end());
		sort(workers.begin(), workers.end());
		int res = 0;
		for (int i = 0; i < jobs.size(); i++) {
			res = max(res, jobs[i] / workers[i] + (jobs[i] % workers[i] != 0));
		}
		return res;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> head = { 3,0,2,6,8,1,7,9,4,2,5,5,0 };
	vector<vector<int>> map = sol.spiralMatrix(3, 5, &head);


	cin >> c;

}