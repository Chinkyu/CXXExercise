// easy question 
// make count array with map and find count is more than 2/n


#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> mp;
		int size = nums.size();

		for (int i : nums) {
			mp[i]++;
		}

		for (auto it = mp.begin(); it != mp.end(); it++) {
			if (it->second > size / 2) return it->first;
		}
		return -1;
	}
};


int main() {
	char c;
	vector<int> vt;
	map<int, int> m;


	cout << ++m[10];

	cout << ++m[10];
	cout << ++m[10];
	cout << m[10];
	cout << m.size();

	cin >> c;
}