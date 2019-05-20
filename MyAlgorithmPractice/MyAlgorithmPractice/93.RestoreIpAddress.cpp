#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool verify(string s) {
		if (stoi(s) < 0 || stoi(s) > 255) return false;
		if (s.length() >= 2 && s[0] == '0') return false;
		return true;
	}
	vector<string> restoreIpAddresses(string s) {
		int l = s.length();
		vector<string> ret;
		string t, ts;

		for (int i = 1; i <= 3 && i < l; ++i) {
			for (int j = i + 1; j <= i+3 && j < l; ++j) {
				for (int k = j + 1; k <= j+3 && k < l; ++k) {
					if (l - k > 3) continue;
					//cout << i << " " << j << " " << k << endl;
					ts.clear();
					t.clear();
					for (int m = 0; m < i; ++m) t.push_back(s[m]);
					if (verify(t) == false) continue;
					ts.append(t);
					ts.push_back('.');

					t.clear();
					for (int m = i; m < j; ++m) t.push_back(s[m]);
					if (verify(t) == false) continue;
					ts.append(t);
					ts.push_back('.');

					t.clear();
					for (int m = j; m < k; ++m) t.push_back(s[m]);
					if (verify(t) == false) continue;
					ts.append(t);
					ts.push_back('.');

					t.clear();
					for (int m = k; m < l; ++m) t.push_back(s[m]);
					if (verify(t) == false) continue;
					ts.append(t);
					
					//cout << ts.c_str() << endl;
					ret.push_back(ts);
				}
			}
		}

		return ret;
	}
};

int main() {
	char c;
	Solution sol;
	//string s = "25525511135";
	//string s = "0000";
	string s = "010010";
	vector<string> ret = sol.restoreIpAddresses(s);

	for (auto it : ret) {
		cout << it << endl;
	}

	cin >> c;
}