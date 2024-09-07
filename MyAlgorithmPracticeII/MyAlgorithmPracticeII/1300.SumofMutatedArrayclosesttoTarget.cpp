// 답봤음 : 바이너리써치... 참,...  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

// 거기에 있는 값중에 인줄 알았는데.. 아니데... => 다시.. 
class _Solution {
public:
	int getVal(vector<int>& arr, vector<int>& acc, int idx) {
		int l = arr.size();
		int ans = 0; 

		if (idx > 0) ans += acc[idx - 1];
		ans += (l - idx) * arr[idx];

		return ans;
	}


	int findBestValue(vector<int>& arr, int target) {
		vector<int> acc;

		sort(arr.begin(), arr.end());

		acc.push_back(arr[0]);
		for (int i = 1; i < arr.size(); ++i) {
			acc.push_back(acc[i - 1] + arr[i]);
		}

		// binar search

		int lidx = 0, ridx = arr.size() - 1;
		int midx = 0;
		while (lidx + 1 < ridx) {
			midx = (lidx + ridx) / 2;

			int val = getVal(arr, acc, midx);

			if (val < target) {
				lidx = midx + 1;
			}
			else if(target < val){
				ridx = midx - 1;
			}
			else {
				return arr[midx];
			}
		}
		cout << lidx << " " << ridx;

		return arr[midx];

	}
};

class __Solution {
public:
	int getVal(vector<int>& arr, vector<int>& acc, int checkval) {
		int l = arr.size();
		int ans = 0;
		int idx = 0;

		vector<int>::iterator low;
		low = lower_bound(arr.begin(), arr.end(), checkval);
		idx = distance(arr.begin(), low);
		if (checkval < arr[idx]) idx--;

		if (idx > 0) ans += acc[idx - 1];
		ans += (l - idx) * arr[idx];

		return ans;
	}


	int findBestValue(vector<int>& arr, int target) {
		vector<int> acc;

		sort(arr.begin(), arr.end());

		acc.push_back(arr[0]);
		for (int i = 1; i < arr.size(); ++i) {
			acc.push_back(acc[i - 1] + arr[i]);
		}

		getVal(arr, acc, 21297);

		// binar search

		int lval = arr[0], rval = arr[arr.size() - 1];
		int mval = 0;
		while (lval + 1 < rval) {
			mval = (lval + rval) / 2;

			int val = getVal(arr, acc, mval);

			if (val < target) {
				lval = mval + 1;
			}
			else if (target < val) {
				rval = mval - 1;
			}
			else {
				return arr[mval];
			}
		}
		//cout << lidx << " " << ridx;

		return mval;

	}
};

class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		int l, r, mi, s = 0, m = -1;
		for (int v : arr) s += v, m = max(m, v);

		if (s <= target) return m; // return the max value since we will keep all nums as is

		for (l = 1, r = m; l < r;) {
			mi = (l + r) / 2;
			s = 0;
			for (int v : arr) s += (v > mi) ? mi : v;
			if (s >= target) r = mi;
			else          l = mi + 1;
		}
		// check if we are 1 step off the target 
		int s1 = 0, s2 = 0;
		for (int v : arr) s1 += (v > l) ? (l) : v, s2 += (v > l - 1) ? (l - 1) : v;

		return (abs(s2 - target) <= abs(s1 - target)) ? l - 1 : l;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> arr = {2, 3, 5};
	//vector<int> arr = { 60864,25176,27249,21296,20204 };

	cout << sol.findBestValue(arr, 10);

	cin >> c;
}