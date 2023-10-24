// hard in debugging 
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
	int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
		int lp = passengers.size();
		sort(buses.begin(), buses.end());
		sort(passengers.begin(), passengers.end());

		int bidx = 0;
		int pidx = 0, rpidx = 0;

		for (; bidx < buses.size() - 1; ++bidx) {
			while (pidx < lp && passengers[pidx] <= buses[bidx]) pidx++;

			// 
			if (pidx - rpidx <= capacity) {
				rpidx = pidx;
			}
			else {
				rpidx += capacity;
			}
		}

		// remained passenger for last bus
		// from rpidx  to end 

		// choose capacity - 1 passenger
		vector<int> rpassenger;
		int lbustime = buses[buses.size() - 1];
		for (int i = 0; i < capacity - 1; ++i) {
			if (rpidx + i >= lp) break;
			if (passengers[rpidx + i] >= lbustime) break;

			rpassenger.push_back(passengers[rpidx + i]);
		}

		// reverse order
		int ans = lbustime;
		if (rpidx + rpassenger.size() < lp) {
			ans = min(ans, passengers[rpidx + rpassenger.size()] - 1);
		}

		// have to go backward continuously
		//for (int i = rpassenger.size() - 1; i >= 0; --i) {
		//	if (rpassenger[i] == ans) {
		//		ans--;
		//	}
		//	else {
		//		break;
		//	}
		//}

		for (int i = rpidx + rpassenger.size() - 1; i >= 0; --i) {
			if (passengers[i] == ans) {
				ans--;
			}
			else {
				break;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> buses = { 20, 30, 10 };
	//vector<int> passengers = { 19, 13, 26, 4, 25, 11,21 };
	//cout << sol.latestTimeCatchTheBus(buses, passengers, 2);

	//vector<int> buses = { 18,8,3,12,9,2,7,13,20,5 };
	//vector<int> passengers = { 13,10,8,4,12,14,18,19,5,2,30,34 };
	//cout << sol.latestTimeCatchTheBus(buses, passengers, 1);


	vector<int> buses = { 6, 8, 18, 17 };
	vector<int> passengers = { 6, 8, 17 };
	cout << sol.latestTimeCatchTheBus(buses, passengers, 1);
	cin >> c;

}