// map  하고 queue대신에 array를 사용해서 간단하게 해결 가능함.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	int minimumSwap(string s1, string s2) {
		int num = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) num++;
		}

		if (num % 0x01 == 0x01) return -1;
		return num / 2;
	}
};

int main() {
	char c;

	Solution sol;

	string s1 = "xx", s2 = "yy";
	cout << sol.minimumSwap(s1, s2);

	cin >> c;
}