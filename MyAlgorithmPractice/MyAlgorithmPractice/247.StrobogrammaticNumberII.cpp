#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;


class Solution {
public:

	vector<vector<char>> reversiblePairs = {
		{ '0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}
	};

	vector<string> generateStroboNumbers(int n, int finalLength) {
		if (n == 0) {
			// 0 ditit strobogrammatic number is an empty string
			return { "" };
		}

		if (n == 1) {
			// 1 digit strobogrammatic numbers
			return { "0", "1", "8" };
		}

		vector<string> prevStroboNums = generateStroboNumbers(n - 2, finalLength);
		vector<string> currStroboNums;

		for (string& prevStroboNum : prevStroboNums) {
			for (vector<char>& pair : reversiblePairs) {
				// add only 0 if it is not first didit
				if (pair[0] != '0' || n != finalLength) {
					currStroboNums.push_back(pair[0] + prevStroboNum + pair[1]);
				}
			}
		}

		return currStroboNums;
	}

	vector<string> findStrobogrammatic(int n) {
		return generateStroboNumbers(n, n);
	}
};

int main() {
	char c;
	Solution sol;

	vector<string> ans = sol.findStrobogrammatic(10);

	for (auto it : ans) {
		cout << it.c_str() << endl;
	}

	//	cout << "test : " << ans << endl;

	cin >> c;
}