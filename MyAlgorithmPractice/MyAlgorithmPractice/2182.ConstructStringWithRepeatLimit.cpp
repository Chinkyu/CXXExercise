//  timeout :  string swith로 하면 안되고 개수를 새려서.. 해야 하는것 같음... 
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

// timeout
class Solution {
public:
	string repeatLimitedString(string s, int repeatLimit) {

		string ans = s;

		sort(ans.begin(), ans.end(), [](char l, char r) {return l > r; });

		int l = ans.size();

		int count = 1;
		char cChar = ans[0];
		int nextIdx = 1;
		for (int i = 1; i < l; ++i) {
			if (ans[i] == cChar) {
				count++;
				if (repeatLimit < count) {
					
					int j = 0;

					for (j = nextIdx; j < l && ans[j] == cChar; ++j);
					if (j >= l) {   // no more next 
						// need to cut till now 
						ans.erase(i);
						return ans;
					}
					else {
						// swap ans[i], ans[j]
						swap(ans[i], ans[j]);
						count = 0;
						if (i + 1 < l) cChar = ans[i + 1];
						nextIdx = i+1;
					}

				}
				else {
					nextIdx = i+1;
				}
			}
			else {
				count = 1;
				cChar = ans[i];
				nextIdx = i + 1;
			}
		}

		return ans;

	}
};


int main() {
	char c;

	Solution sol;

	string s = "robnsdvpuxbapuqgopqvxdrchivlifeepy";

	cout << sol.repeatLimitedString(s, 2);

	cin >> c;

}