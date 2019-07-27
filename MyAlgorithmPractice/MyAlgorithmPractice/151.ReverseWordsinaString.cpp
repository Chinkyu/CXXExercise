#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		istringstream input(s);
		stack<string> stack;
		string ans;

		string token;
		while (getline(input, token, ' ')) {
			if (token == "") continue;
			stack.push(token);
		}

		while (stack.size() > 0) {
			ans.append(stack.top());
			stack.pop();
			if (stack.size() > 0) ans.push_back(' ');
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	string s = "the sky is  blue";

	cout << sol.reverseWords(s);

	cin >> c;
}