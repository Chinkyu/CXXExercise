//  easy -  tricky for exception handling 
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

using namespace std;

class Solution {
public:
	long long minimumHealth(vector<int>& damage, int armor) {
		long long ans = 0;
		int l = damage.size();

		for (auto &it : damage) ans += it;

		if (armor == 0) return ans + 1;

		sort(damage.begin(), damage.end());

		vector<int>::iterator low = lower_bound(damage.begin(), damage.end(), armor);
		if (low == damage.end()) {
			ans -= damage[l - 1];
		}
		else if(low - damage.begin() == 0) {
			if (*low >= armor) {
				ans -= armor;
			}
			else {
				ans -= *low;
			}
		}
		else {
			if (*low == armor) {
				ans -= armor;
			}
			else {
//				if (*(low - 1) == 0) {
					ans -= armor;
//				}
//				else {
//					ans -= *(low - 1);
//				}
			}
		}

		ans++;
		return ans;

	}
};

int main() {
	char c;

	Solution sol;


	vector<int>::iterator low, up;
	//vector<int> v = { 1, 2, 3, 1 };
	vector<int> v = { 1, 2, 4, 4, 4, 4,5, 6, 7,9 };
	//sort(v.begin(), v.end());

	low = lower_bound(v.begin(), v.end(), 3);
	up = lower_bound(v.begin(), v.end(), 7);

	cout << "low" << low - v.begin() << endl;
	cout << "up" << up - v.begin() << endl;
	
	

	vector<int> damage = {1, 5, 0, 0, 5};
	cout << sol.minimumHealth(damage, 3);
	
	
	cin >> c;




}