//  디버깅 시간 걸림... 

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
	string largestPalindromic(string num) {
		string ans;
		vector<int> count(10, 0);

		for (auto it : num) {
			count[it - '0']++;
		}

		string front, back;
		for (int i = 9; i >= 1; --i) {
			if (count[i] >= 2) {
				int twonum = count[i] / 2;
				for (int j = 0; j < twonum; ++j) {
					front.push_back('0' + i);
					back.push_back('0' + i);
					count[i] -= 2;
				}
			}
		}

		
		if (front.size() > 0) {
			int twonum = count[0] / 2;
			for (int j = 0; j < twonum; ++j) {
				front.push_back('0');
				back.push_back('0');
				count[0] -= 2;
			}
		}

		// Add remain center into front
		for (int i = 9; i >= 0; --i) {
			if (count[i] > 0) {
				front.push_back('0' + i);
				break;
			}
		}

		// push back as reverse
		for (int i = back.size() - 1; i >= 0; --i) {
			front.push_back(back[i]);
		}

		return front;
	}
};

int main() {
	char c;

	Solution sol;

	string num = "00001105";//"444947137";

	cout << sol.largestPalindromic(num);

	cin >> c;
}