//  답봤음 : 신박한 방법... 
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

// memory limit exceed
class RangeFreqQuery {
public:
	vector<unordered_map<int, int>> vm;
	RangeFreqQuery(vector<int>& arr) {
		int l = arr.size();
		unordered_map<int, int> tm;

		for (int i = 0; i < l; ++i) {
			tm[arr[i]]++;
			vm.push_back(tm);
		}

	}

	int query(int left, int right, int value) {
		return (left - 1 < 0) ? (vm[right][value] - 0) : (vm[right][value] - vm[left - 1][value]);
	}
};


// 신박한.
class RangeFreqQuery {
	unordered_map<int, vector<int>> mp;
public:
	RangeFreqQuery(vector<int>& arr) {
		for (int i = 0; i < size(arr); i++) mp[arr[i]].push_back(i);
	}

	int query(int L, int R, int V) {
		return upper_bound(begin(mp[V]), end(mp[V]), R) - lower_bound(begin(mp[V]), end(mp[V]), L);
	}
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
	char c;



	vector<int> arr = { 12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56 };
	RangeFreqQuery sol(arr);
	cout << sol.query(0, 11, 33);

	cin >> c;
}