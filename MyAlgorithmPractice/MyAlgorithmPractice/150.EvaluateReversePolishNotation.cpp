#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	stack<int> st;
	int evalRPN(vector<string>& tokens) {
		int res = 0;
		st.empty();

		for (auto it : tokens) {
			if (it == "-" || it == "+" ||
				it == "*" || it == "/") {
				int r = st.top();
				st.pop();
				int l = st.top();
				st.pop();
				switch (it[0]) {
				case '+':
					st.push(l + r);
					break;
				case '-':
					st.push(l - r);
					break;
				case '*':
					st.push(l * r);
					break;
				case '/':
					st.push(l / r);
					break;
				}
			}
			else {
				st.push(stoi(it));
			}
		}
		return st.top();
	}
};

int main() {
	Solution sol;
	char c;
	vector<string> v = { "2", "1", "+", "3", "*" };
	cout << sol.evalRPN(v);

	cin >> c;
}