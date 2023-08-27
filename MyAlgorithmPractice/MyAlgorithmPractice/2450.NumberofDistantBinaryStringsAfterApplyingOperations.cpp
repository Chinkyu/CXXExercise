// 답봤고.. 어이 없음. 
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

// 내용과는 상관 없이 길이와만 관련 있다고 함....  답이... 이이 없음. 
class Solution
{
public:
	int countDistinctStrings(string s, int k)
	{
		// in C++, we'd better to account for overflows...
		uint64_t p = 1;
		for (int i = 0; i < s.size() - k + 1; i++)
			p *= 2, p %= 1000000007;
		return p;
	}
};

class _Solution {
public:
	int countDistinctStrings(string s, int k) {
		unordered_map<string, int> done, notdone;
		int l = s.size();

		notdone[s] = 1;

		while (!notdone.empty()) {
			string ns = notdone.begin()->first;
			notdone.erase(ns);
			done[ns] = 1;
			for (int i = 0; i <= l - k; ++i) {
				string ts = ns;
				for (int j = i; j < i + k; ++j) {
					ts[j] = (ts[j] == '0') ? '1' : '0';
				}

				if (done.find(ts) == done.end()) {
					notdone[ts] = 1;
				}
			}

		}
		return done.size();

	}
};


int main() {
	char c;

	Solution sol;
	
	string s = "11011100001011000011111000101011111111101101011010";//  "10110"; // "1001"; // 

	cout << sol.countDistinctStrings(s, 14);

	cin >> c;
}