//  ½±°Ô ÇØ°áµÊ... 

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
	int garbageCollection(vector<string>& garbage, vector<int>& travel) {

		int midx = 0, pidx = 0, gidx = 0;
		int mtime = 0, ptime = 0, gtime = 0;

		for (int i = 0; i < garbage.size(); ++i) {
			int mcount = 0, pcount = 0, gcount = 0;

			for (auto it : garbage[i]) {
				if (it == 'M') mcount++;
				if (it == 'P') pcount++;
				if (it == 'G') gcount++;
			}

			// m
			if (mcount > 0) {
				for (int j = midx; j < i; j++) mtime += travel[j];
				midx = i;
				mtime += mcount;
			}
			// p
			if (pcount > 0) {
				for (int j = pidx; j < i; j++) ptime += travel[j];
				pidx = i;
				ptime += pcount;
			}
			//g			
			if (gcount > 0) {
				for (int j = gidx; j < i; j++) gtime += travel[j];
				gidx = i;
				gtime += gcount;
			}
		}

		return mtime + ptime + gtime;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> garbage = { "G", "P", "GP", "GG" };
	vector<int> travel = { 2, 4, 3 };

	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}