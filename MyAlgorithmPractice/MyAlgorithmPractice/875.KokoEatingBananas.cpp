//바이너리 써치로 해서 해결...  float, long long  으로 해야함....  요거때문에 좀 까다로웠음
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

	int necessaryHours(vector<int> &piles, int v) {
		int nh = 0;

		for (auto it : piles) {
			nh += ceil(((double)it) / v);
		}
		return nh;
	}

	int minEatingSpeed(vector<int>& piles, int h) {

		long long sum = 0;

		for (auto it : piles) sum += it;

		long long stV = ceil(((float)sum) / h);
		long long edV = sum;
		long long mdV = (stV + edV) / 2;
		// binary search 

		while (stV < edV) {
			long long nh = necessaryHours(piles, mdV);
			//cout << "V:" << mdV << "nh:" << nh << endl;
			if (nh <= h) {
				edV = mdV;
			}
			else {
				stV = mdV;
			}
			mdV = (stV + edV) / 2;

			if (stV + 1 == edV) break;
		}

		if(h >= necessaryHours(piles, stV)) return stV;

		return edV;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> piles = {1000000000, 1000000000};//{ 30, 11, 23, 5, 20 }; //  { 3, 6, 7, 11 };

	cout << sol.minEatingSpeed(piles, 3);

	cin >> c;
}