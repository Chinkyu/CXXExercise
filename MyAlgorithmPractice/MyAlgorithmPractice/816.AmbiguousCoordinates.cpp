//  check_last_number 하는데 시간 걸리고...  스페이스 넣는데도 시간 걸림..
// 시간 생각 보다 많이 걸린 문제.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<string> ans;

	bool check_last_number(string &cs) {
		int idx = cs.size() - 1;

		while (cs[idx] != ',' && idx > 0) idx--;

		string s;
		if (idx == 0) {
			s = cs;
		}
		else {
			s = cs.substr(idx + 2, cs.size() - idx);
		}

		//float to_float = stof(s);
		//string s2 = to_string(to_float);
		//if (s.size() == s2.size()) return true;
		int num_point = 0;
		for (auto it : s) if (it == '.') { num_point++; }

		if (num_point > 1) return false;

		if (num_point == 0) {
			if (s.size() != 1 && s.front() == '0') return false;
		}
		else {
			if (s.front() == '0') {
				if (s[1] != '.') return false;
			}

			if (s.back() == '0') return false;
		}

		return true;
	}

	void traverse(string &s, string cs, int idx, int num_comma) {
		int l = s.size();
		char ec = s[idx];

		char pc = s[idx - 1];

		if (ec == ')') {
			// check last valid
			if (check_last_number(cs) == false) return;

			// add only 1 comma string 
			if (num_comma == 1) {
				cs = '(' + cs + ')';
				ans.push_back(cs);
			}
			return;
		}

		// no adding 

		traverse(s, cs + ec, idx + 1, num_comma);

		// adding .
		if (pc != '.' && pc != ',' && pc != '(') {
			//cs.push_back('.');
			traverse(s, cs + '.' + ec, idx + 1, num_comma);
		}

		// adding ,
		if (pc != '.' && pc != ',' && pc != '(') {

			if (check_last_number(cs) == false) return;

			// if we put two comma it become three numbers
			if (num_comma >= 1) return;

			//cs.push_back(',');
			traverse(s, cs + ", " + ec, idx + 1, num_comma + 1);
		}


	}

	vector<string> ambiguousCoordinates(string s) {
		ans.clear();
		string cs = "";
		traverse(s, cs, 1, 0);
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//string s = "(123)";
	//string s = "(0123)";
	string s = "(00011)";
	vector<string> ans = sol.ambiguousCoordinates(s);

	for (auto it : ans) {
		cout << it << endl;
	}

	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}