// normal  :  숫자로 converting 할려고 하다가 시간걸림 string 으로 converting -> easy 
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

	int convert(vector<int>& mapping, int in) {
		int out = 0;

		string ins = to_string(in);

		for (int i = 0; i < ins.size(); ++i) {
			ins[i] = mapping[ins[i] - '0'] + '0';
		}
		
		return stoi(ins);
	}

	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		int l = nums.size();
		vector<pair<int, int>>  p;

		for (auto &it : nums) {
			p.push_back(make_pair(it, convert(mapping, it)));
		}

		sort(p.begin(), p.end(), [](pair<int, int> &l, pair<int, int> &r) {
			//if (l.second == r.second) return l.first < r.first;
			return l.second < r.second;
		});

		vector<int> ans;
		for (auto &it : p) ans.push_back(it.first);
		return ans;

	}
};

int main() {
	char c;

	Solution sol;

	vector<int> mapping = { 8,9,4,0,2,1,3,5,7,6 };
	vector<int> nums = { 991,338,38 };

	vector<int> ans = sol.sortJumbled(mapping, nums);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;

}