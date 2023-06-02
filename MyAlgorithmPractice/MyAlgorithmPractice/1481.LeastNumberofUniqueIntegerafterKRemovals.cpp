// 쉽게 풀림.. 


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
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {		unordered_map<int, int> c;

		for (auto it : arr) c[it]++;
		vector<int> cnt;		for (auto it : c) cnt.push_back(it.second);		sort(cnt.begin(), cnt.end());		int l = cnt.size();		int sum = 0;		for (int i = 0; i < l; ++i) {			sum += cnt[i];			if (sum > k) return l - i;		}		return 0;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> arr = { 5, 5, 4 };
	cout << sol.findLeastNumOfUniqueInts(arr, 1);
	cin >> c;
}