// easy :  lattice point 의 의미가 .....  
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

	int door() {
		vector<int> door(51, 0);

		for (int i = 1; i <= 50; ++i) {  // man
			for (int j = i; j <= 50; ++j) { // door
				if (j%i == 0) door[j]++;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= 50; ++i) {
			if (door[i] % 2 == 1) cnt++;
		}

		return cnt;
	}
};

int main() {
	char c;

	Solution sol;


	cout << sol.door();

	cin >> c;

}