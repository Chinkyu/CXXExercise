// normal : sliding window 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


// timeout
class _Solution {
public:
	vector<long long> getDistances(vector<int>& arr) {
		unordered_map<int, list<int>> m;
		vector<long long> ans;

		for (int i = 0; i < arr.size(); ++i) {
			m[arr[i]].push_back(i);
		}

		for (int i = 0; i < arr.size(); ++i) {
			int sum = 0;
			for (auto &it : m[arr[i]]) {
				sum += abs(i - it);
			}
			ans.push_back(sum);
		}
		return ans;
	}
};

class Solution {
public:
	vector<long long> getDistances(vector<int>& arr) {
		unordered_map<int, vector<int>> m;
		vector<long long> ans(arr.size(), 0);

		for (int i = 0; i < arr.size(); ++i) {
			m[arr[i]].push_back(i);
		}

		for (auto &it : m) {
			int l = it.second.size();
			int idx = 0;
			long long bsum = 0, asum = 0;
			vector<int> &ia = it.second;
			for (int i = 1; i < l; ++i) asum += abs(ia[0] - ia[i]);
			ans[it.second[idx++]] = asum;

			while (idx < l) {
				bsum = bsum + abs(ia[idx - 1] - ia[idx]) * idx;
				asum = (idx == l - 1)?  0 : asum - abs(ia[idx-1] - ia[idx]) *(l - idx);
				ans[ia[idx++]] = asum + bsum;
			}
		}

		return ans;
	}
};



int main() {
	char c;

	Solution sol;
	vector<int> arr = { 2,1,3,1,2,3,3 };

	vector<long long> ans = sol.getDistances(arr);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}