#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ALPHA_NUM (256)  // ascii 
using namespace std;

class Solution {
public:

	vector<pair<int, int>> count;

	// compare function for send pair
	static bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
		return (a.second > b.second);
	}

	string frequencySort(string s) {
		string ans;
		// init count;
		for (int i = 0; i < ALPHA_NUM; i++) {
			count.push_back(make_pair(i, 0));
		}
	
		// accumurate count array
		for (int i = 0; i < s.length(); i++) {
			count[s[i]].second++;
		}

		// sort with second pair
		sort(count.begin(), count.end(), sortbysec);

		for (int i = 0; i < count.size() && count[i].second != 0; i++) {
			for (int j = 0; j < count[i].second; j++) {
				ans.push_back(count[i].first);
			}
		}

		return ans;
	}
};




int main() {
	char c;
	string s = "AaccccggggFFFFFFFFbb";
	Solution sol;
	cout << sol.frequencySort(s);

	cin >> c;

}