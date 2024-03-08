//  easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int wateringPlants(vector<int>& plants, int capacity) {
		int l = plants.size();

		int idx = 0;
		int ans = 0;

		int remain = capacity;
		while (idx < l) {
			//if(idx > capacity) // do not need to check 
			if (plants[idx] <= remain) {
				remain -= plants[idx];
				idx++;
				ans++;
			}
			else {  // need water is less than remain
				ans += (idx + idx + 1);
				remain = capacity - plants[idx];
				idx++;
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> plants = { 2,2,3,3 };
	cout << sol.wateringPlants(plants, 5);

	cin >> c;
}