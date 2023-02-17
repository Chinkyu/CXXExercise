
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class BrowserHistory {
public:
	stack<string> bh, fh;

	BrowserHistory(string homepage) {
		while (!bh.empty()) bh.pop();
		while (!fh.empty()) fh.pop();
		bh.push(homepage);
	}

	void visit(string url) {
		bh.push(url);
		while (!fh.empty()) fh.pop();
	}

	string back(int steps) {
		string url;

		if (bh.size() == 1) return bh.top();
		for (int i = 0; i < steps; ++i) {
			if (bh.size() == 1) return bh.top();
			url = bh.top();
			bh.pop();
			fh.push(url);
			url = bh.top();
		}

		return url;
	}

	string forward(int steps) {
		string url;

		if (fh.size() == 0) return bh.top();
		for (int i = 0; i < steps; ++i) {
			if (fh.size() == 0) return bh.top();
			url = fh.top();
			fh.pop();
			bh.push(url);
		}

		return url;
	}
};
int main() {
	char c;
	BrowserHistory b("leetcode.com");

	cout << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}