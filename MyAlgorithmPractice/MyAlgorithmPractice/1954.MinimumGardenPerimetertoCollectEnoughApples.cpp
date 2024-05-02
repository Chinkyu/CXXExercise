//  답봤음....  등비 간단한 수식으로 나올것 같음. 
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
	long long minimumPerimeter(long long x) {
		long long l = 1, r = 100000, m;
		while (l < r) {
			m = (l + r) / 2;
			if (m * m * m * 4 + m * m * 6 + m * 2 >= x)
				r = m;
			else
				l = m + 1;
		}
		return l * 8;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> piles = { 4, 3, 6, 7 };

	cout << sol.minStoneSum(piles, 3);

	cin >> c;
}