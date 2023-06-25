//  :XXXX: 그냥 답 봤음..   DP로 풀었다는데.. 들여다 봐야함... 
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
	int minExtraChar(string s, vector<string>& dictionary) {
		set<string> str;
		int n1 = s.size();
		int n2 = dictionary.size();
		for (int i = 0; i < n2; i++)
		{
			str.insert(dictionary[i]);
		}
		vector<int> dp(n1 + 1, 0);
		//0 1 2 3 4 5 6
		for (int i = 1; i <= n1; i++)
		{
			dp[i] = dp[i - 1] + 1;
			for (int j = i; j >= 1; j--)
			{
				string temp = s.substr(j - 1, i - j + 1);
				if (str.count(temp))
				{
					dp[i] = min(dp[i], dp[j - 1]);
				}
			}
		}
		return dp[n1];
	}
};


class _Solution {
public:

	int max_len = 0;

	bool isOverLab(string &sM, vector<int> &dicI) {
		for (int i = dicI[0]; i < dicI[0] + dicI[1]; ++i) {
			if (sM[i] == 'A') return true;
		}
		return false;
	}

	void traverse(string &s, vector<vector<int>> &dicV, vector<int> &dicVM, string &sM, int idx) {
		int n = dicV.size();

		if (idx == n) {
			int tmax = 0;
			for (int i = 0; i < n; ++i) {
				if (dicVM[i] == 1) tmax += dicV[i][1];
			}

			max_len = max(max_len, tmax);
			return;
		}


		// use this idx
		if (dicV[idx][0] != -1 && isOverLab(sM, dicV[idx]) == false ) {
			for (int i = dicV[idx][0]; i < dicV[idx][0] + dicV[idx][1]; ++i) {
				sM[i] = 'A';
			}
			dicVM[idx] = 1;

			traverse(s, dicV, dicVM, sM, idx + 1);

			for (int i = dicV[idx][0]; i < dicV[idx][0] + dicV[idx][1]; ++i) {
				sM[i] = 'F';
			}
			dicVM[idx] = 0;
		}

		// not use this idx
		traverse(s, dicV, dicVM, sM, idx + 1);

	}

	int minExtraChar(string s, vector<string>& dictionary) {
		int n = dictionary.size();
		vector<vector<int>> dicV(n, vector<int>(2, 0));

		for (int i = 0; i < n; ++i) {
			size_t found = s.find(dictionary[i]);
			if (found != s.npos) {
				dicV[i][0] = found;
				dicV[i][1] = dictionary[i].size();
			}
			else {
				dicV[i][0] = -1;
			}
		}

		string sM(s.size(), 'F');
		vector<int> dicVM(n, 0);
		max_len = 0;

		traverse(s, dicV, dicVM, sM, 0);

		return s.size() - max_len;

	}
};


int main() {
	char c;

	Solution sol;

//	string s = "leetscode";
//	vector<string> dictionary = { "leet", "code", "leetcode" };

	string s = "sayhelloworld";
	vector<string> dictionary = { "hello", "world"};


	cout << sol.minExtraChar(s, dictionary);

	cin >> c;
}