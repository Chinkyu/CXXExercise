// Its OK.... : tricky for moduler
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

class Solution {
public:
	int firstDayBeenInAllRooms(vector<int>& nextVisit) {
		int l = nextVisit.size();
		vector<int> v(l, 0);
		vector<int> fVisit(l, 0);

		long long i = 0, vn = 0;
		fVisit[0] = 0;
		while (i != l - 1) {
			v[i]++;
			vn++;

			if (v[i] % 2 == 1) {
				//i = nextVisit[i];
				fVisit[i] = vn;
				vn += fVisit[i] - fVisit[nextVisit[i]] + 1;
				if (vn < 0) vn += 1000000007;
				i++;
			}
			else {
				fVisit[i] = vn;
				i++;
			}

			vn %= 1000000007;
		}

		return vn % 1000000007;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nextVisit = { 0,0,2 }; //{ 0, 0 };

	cout << sol.firstDayBeenInAllRooms(nextVisit);

	cin >> c;
}