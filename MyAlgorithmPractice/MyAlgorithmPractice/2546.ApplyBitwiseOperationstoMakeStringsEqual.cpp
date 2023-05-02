// Easy 
//   10, 01 -> 11,  11 -> 01,10  
//  00 인 경우만 path 가 없으니..  0으로만 되어 있는경우만 아니면 모두 변위 가능 ... 
// 이것 알면 쉬움.....    이걸 다 해볼려고 했으면....  못풀었을것 같음. 

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
	bool makeStringsEqual(string s, string target) {
		int l = s.size();

		int sOneNum = 0, tOneNum = 0;
		for (auto it : s) if (it == '1') sOneNum++;
		for (auto it : target) if (it == '1') tOneNum++;

		if (s != target && 
			(sOneNum == 0 || tOneNum == 0)) return false;
		return true;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.makeStringsEqual("1010", "0110");

	cin >> c;
}