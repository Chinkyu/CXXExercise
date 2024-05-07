// 문제 이상
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
	string maximumNumber(string num, vector<int>& change) {
		int l = num.size();

		for (int i = 0; i < l; ++i) {
			if ((num[i] - '0') < change[num[i] - '0']) num[i] = change[num[i] - '0'] + '0';
		}

		return num;
	}
};

int main() {
	char c;
	Solution sol;

	string num = "021";
	vector<int> change = { 9,4,3,5,7,2,1,9,0,6 };

	cout << sol.maximumNumber(num, change);

	cin >> c;
}