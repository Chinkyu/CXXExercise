// 타임아웃나서 답 봤음... set으로 푸는 답 봤음.. 

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

// set 가지고 풀줄이야... 
class Solution {
public:
	bool hasAllCodes(string s, int k) {
		unordered_set <string> set;
		string temp = s.substr(0, k);
		set.insert(temp);
		int n = s.size();
		for (int i = k; i < n; i++) {
			temp.erase(temp.begin());
			temp.push_back(s[i]);
			set.insert(temp);
		}
		return set.size() == pow(2, k);

	}
};

// timeout 
class _Solution {
public:
	string ss;
	bool notFound = false;
	void traverse(int k, int i, string str) {

		if (notFound == true) return;
		if (i == k) {
			if (ss.find(str) == std::string::npos) {
				notFound = true;
				return;
			}
			return;
		}

		traverse(k, i + 1, str + '0');
		traverse(k, i + 1, str + '1');
	}

	bool hasAllCodes(string s, int k) {
		ss = s;
		notFound = false;
		string s1;
		traverse(k, 0, s1);
		return !notFound;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "00110110";
	cout << sol.hasAllCodes(s, 2);

	cin >> c;
}