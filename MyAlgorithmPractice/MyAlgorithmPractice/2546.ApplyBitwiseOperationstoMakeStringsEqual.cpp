// Easy 
//   10, 01 -> 11,  11 -> 01,10  
//  00 �� ��츸 path �� ������..  0���θ� �Ǿ� �ִ°�츸 �ƴϸ� ��� ���� ���� ... 
// �̰� �˸� ����.....    �̰� �� �غ����� ������....  ��Ǯ������ ����. 

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