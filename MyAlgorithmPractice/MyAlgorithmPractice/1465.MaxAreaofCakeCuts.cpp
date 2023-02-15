// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int hm = 0, vm = 0;
		int ans = 0;

		// add at the end of element
		horizontalCuts.push_back(h);
		verticalCuts.push_back(w);

		// sort vector
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		// find horizontal max gap
		int st = 0;
		for (auto it : horizontalCuts) {
			hm = max(hm, it - st);
			st = it;
		}

		// find vertical max gap
		st = 0;
		for (auto it : verticalCuts) {
			vm = max(vm, it - st);
			st = it;
		}


		ans = (static_cast<long long>(hm) * static_cast<long long>(vm)) % (1000000007);



		return ans;
	}
};



int main() {
	char c;
	Solution sol;

	vector<int> hv = { 5, 2, 6, 3 }, vv = { 1, 4 };

	cout << sol.maxArea(8, 5, hv, vv);

	//	cout << "test : " << ans << endl;

	cin >> c;
}