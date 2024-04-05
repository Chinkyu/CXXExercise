//  ¥‰∫√¿Ω : »«∏¢.  Build Regular expression and matching 
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
	vector<string> splitByDelimeter(string str) {
		stringstream ss(str);
		string s;
		vector<string> res;
		while (getline(ss, s, '#')) {
			res.push_back(s);
		}
		return res;
	}

	bool matchStrings(const string &A, const string &B) {
		for (int i = 0; i < A.size(); ++i) {
			if (A[i] == '.') continue;
			if (A[i] != B[i]) return false;
		}
		return true;
	}

	bool placeWordInCrossword(vector<vector<char>>& board, string word) {
		string rev = word;
		reverse(begin(rev), end(rev));
		int n = board.size();
		int m = board[0].size();
		string str;
		for (int i = 0; i < n; ++i) {
			str = "";
			for (int j = 0; j < m; ++j) {
				str += (board[i][j] == ' ' ? '.' : board[i][j]);
			}
			auto res = splitByDelimeter(str);
			for (const string &x : res) {
				if (x.size() != word.size()) continue;
				if (matchStrings(x, word) || matchStrings(x, rev)) return true;
			}
		}

		for (int j = 0; j < m; ++j) {
			str = "";
			for (int i = 0; i < n; ++i) {
				str += (board[i][j] == ' ' ? '.' : board[i][j]);
			}
			auto res = splitByDelimeter(str);
			for (const string &x : res) {
				if (x.size() != word.size()) continue;
				if (matchStrings(x, word) || matchStrings(x, rev)) return true;
			}
		}
		return false;
	}
};
int main() {
	char c;
	Solution sol;

	vector<vector<int>> lights = { {-3, 2}, {1, 2}, {3, 3} };

	cout << sol.brightestPosition(lights);

	cin >> c;
}