//  easy
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
	int countCollisions(string directions) {
		int l = directions.size();

		int colNum = 0;

		int i = 0;
		while(i < l) {
			char c = directions[i];
			int e = i;
			while ((e + 1) < l && directions[e + 1] == c) e++;

			switch (c) {
			case 'L' :
				if (i != 0 /* && R or S */) colNum += (e - i + 1);
				break;
			case 'R' :
				if (e != l - 1) colNum += (e - i + 1);
				break;
			case 'S' :

				break;
			}
			i = e + 1;
		}

		return colNum;
	}
};


int main() {
	char c;

	Solution sol;


	string directions = "RLRSLL";
	cout << sol.countCollisions(directions);

	cin >> c;

}