#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		istringstream iss(path);
		list<string> sl;

		string tok;
		while (getline(iss, tok, '/')) {
			if (tok.size() <= 0) continue;
			if (tok == ".") continue;
			else if (tok == "..") {
				if (sl.size() != 0) sl.pop_back();
			}
			else {
				sl.push_back("/" + tok);
			}
		}

		string ans; // = "/";
		for (auto it : sl) {
			ans += it;
		}

		if (ans.size() == 0) ans = "/";
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	//string s = "/home/./disk//";
	string s = "/../";

	cout << sol.simplifyPath(s);

	cin >> c;
}