// 답 참조함 : momoization 만 하면 되는데... 쯧쯧... 
// 왜 그런거는 생각을 못하나..!!!!  쯧쯧... 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


// just add mimoization : make it pass.... 
class Solution {
public:
	unordered_map<string, int> m;
	bool isGotAnswer = false;
	int t_min = INT_MAX;
	int t_max = 1;
	unordered_map<string, bool> memo;

	bool traverse(string& s, int idx, int l) {

		if (memo.find(s.substr(idx)) != memo.end()) return memo[s];

		if (isGotAnswer == true) return true;

		if (idx == l) {
			isGotAnswer = true;
			return true;
		}

		for (int i = t_min; i <= t_max; ++i) {
			if (m.find(s.substr(idx, i)) != m.end()) {
				if (true == traverse(s, idx + i, l)) {
					memo[s.substr(idx)] = true;
					return true;
				}
			}
		}

		memo[s.substr(idx)] = false;
		return false;
	}


	bool preCheck(string& s, vector<string>& wordDict) {
		vector<int> cs(26), cw(26);

		for (int i = 0; i < s.size(); ++i) cs[s[i] - 'a'] = 1;
		for (auto& it : wordDict) {
			for (int i = 0; i < it.size(); ++i) cw[it[i] - 'a'] = 1;
		}

		for (int i = 0; i < 26; ++i) {
			if (cs[i] == 1 && cw[i] == 0) return false;
		}
		return true;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		t_min = INT_MAX;
		t_max = 1;
		isGotAnswer = false;
		memo.clear();

		if (false == preCheck(s, wordDict)) return false;

		for (auto& it : wordDict) {
			m[it] = 1;
			t_min = min(t_min, static_cast<int>(it.size()));
			t_max = max(t_max, static_cast<int>(it.size()));
		}

		traverse(s, 0, s.size());

		return isGotAnswer;
	}
};


// Timeout.. 
class _Solution {
public:
	unordered_map<string, int> m;
	bool isGotAnswer = false;
	int t_min = INT_MAX;
	int t_max = 1;

	void  traverse(string& s, int idx, int l) {

		if (isGotAnswer == true) return;

		if (idx == l) {
			isGotAnswer = true;
			return;
		}

		for (int i = t_min; i <= t_max; ++i) {
			if (m.find(s.substr(idx, i)) != m.end()) {
				traverse(s, idx + i, l);
			}
		}
	}


	bool preCheck(string& s, vector<string>& wordDict) {
		vector<int> cs(26), cw(26);

		for (int i = 0; i < s.size(); ++i) cs[s[i] - 'a'] = 1;
		for (auto& it : wordDict) {
			for (int i = 0; i < it.size(); ++i) cw[it[i] - 'a'] = 1;
		}

		for (int i = 0; i < 26; ++i) {
			if (cs[i] == 1 && cw[i] == 0) return false;
		}
		return true;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		t_min = INT_MAX;
		t_max = 1;
		isGotAnswer = false;

		if (false == preCheck(s, wordDict)) return false;

		for (auto& it : wordDict) {
			m[it] = 1;
			t_min = min(t_min, static_cast<int>(it.size()));
			t_max = max(t_max, static_cast<int>(it.size()));
		}

		traverse(s, 0, s.size());

		return isGotAnswer;
	}
};

int main() {
	char c;
	Solution sol;
	string s = "leetcode";
	vector<string> wordDict = { "leet","code" };
	//vector<int> nums = { 10,4,4,10,10,6,2,3 };

	cout << sol.wordBreak(s, wordDict);

	cin >> c;
}