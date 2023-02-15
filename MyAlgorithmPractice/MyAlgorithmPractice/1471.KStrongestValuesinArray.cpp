// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// sort function : big to small
bool sortbysecandfirst(const pair<int, int> &a, const pair<int, int> &b) {

	if (a.second == b.second)
		return (a.first > b.first);

	return (a.second > b.second);
}

class Solution {
public:



	vector<int> getStrongest(vector<int>& arr, int k) {
		vector<int> ans;
		vector<pair<int, int>>  srted;
		int len = arr.size();

		sort(arr.begin(), arr.end());
		int mid_idx = (len - 1) / 2;

		for (auto it : arr) {
			srted.push_back(pair<int, int>(it, abs(it - arr[mid_idx])));
		}

		sort(srted.begin(), srted.end(), sortbysecandfirst);

		for (int i = 0; i < k; ++i) ans.push_back(srted[i].first);

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> arr = { 1, 2, 3, 4, 5 };

	for (auto it : sol.getStrongest(arr, 2)) {
		cout << it << " ";
	}
	cout << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}