//  Normal : binary search
// 문제가 문제 있음  문제 max 값이 안맞음.. !!! 
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:

	long long getTotalTrip(vector<int>& time, long long atTime) {
		long long totalTrip = 0;

		for (auto &it : time) {
			totalTrip += atTime / it;
		}
		return totalTrip;
	}

	long long minimumTime(vector<int>& time, int totalTrips) {
		long long lTime = 0, rTime = 10000000000;//   000000000;

		do {
			long long mTime = (lTime + rTime) / 2;
			long long mTotalTrip = getTotalTrip(time, mTime);

			//if (mTotalTrip == totalTrips) {
				//return mTime;
			//}
			//else 
			if (mTotalTrip < totalTrips) {
				lTime = mTime;
			}
			else {
				rTime = mTime;
			}
		} while (lTime < rTime - 1);

		long long lTotalTrip = getTotalTrip(time, lTime);
		long long rTotalTrip = getTotalTrip(time, rTime);

		if (totalTrips <= lTotalTrip) {
			return lTime;
		}
		else {
			return rTime;
		}
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> time = { 5, 10, 10 };

	cout << sol.minimumTime(time, 9);

	cin >> c;

}