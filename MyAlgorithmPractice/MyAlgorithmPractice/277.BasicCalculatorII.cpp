#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:

	bool get_token(string &s, int &st, string &tok) {

		if (s.size() <= st ) return false;

		for (int i = st; i < s.size(); ++i) {
			switch (s[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
				tok = s.substr(st, i - st);
				st = i;
				return true;
				break;
			}
		}

		tok = s.substr(st, s.size()-st);
		st = s.size();
		return true;
	}


	int calculate(string s) {
		int st_idx = 0;
		int size = s.size();
		stack<int> nums;
		stack<char> op;
		int ans;

		char opr1 = ' ';
		string token;
		while (get_token(s, st_idx, token)) {
			if (st_idx == s.size()) {
				if(token.size() >= 0) nums.push(stoi(token));
				break;
			}
			switch (s[st_idx]) {
			case '+':
			case '-':
				if (opr1 == '+') {
					int num1 = nums.top();
					nums.pop();
					int num2;
					if (token.size() <= 0) {
						num2 = nums.top();
						nums.pop();
					}
					else {
						num2 = stoi(token);
					}
					nums.push(num1 + num2);
					//nums.push(stoi(token));
				}
				else if (opr1 == '-') {
					int num1 = nums.top();
					nums.pop();
					int num2;
					if (token.size() <= 0) {
						num2 = nums.top();
						nums.pop();
						nums.push(num2 - num1);
					}
					else {
						num2 = stoi(token);
						nums.push(num1 - num2);
					}
					//nums.push(num2 - num1);
					//nums.push(stoi(token));
				}
				else {
					if (token.size() > 0) nums.push(stoi(token));
				}
				opr1 = s[st_idx++];
				break;
			case '*':
				{
					string token2;
					int num1;
					if (token.size() <= 0) {
						num1 = nums.top();
						nums.pop();
					}
					else {
						num1 = stoi(token);
					}
					get_token(s, ++st_idx, token2);
					nums.push(num1 * stoi(token2));
					break;
				}
			case '/':
				{
					string token2;
					int num1;
					if (token.size() <= 0) {
						num1 = nums.top();
						nums.pop();
					}
					else {
						num1 = stoi(token);
					}
					get_token(s, ++st_idx, token2);
					nums.push(num1 / stoi(token2));
					break;
				}
			default:
				nums.push(stoi(token));
				break;
			}
		}

		if (opr1 == '+') {
			int num1 = nums.top();
			nums.pop();
			int num2 = nums.top();
			nums.pop();
			ans = num1 + num2;
		}
		else if (opr1 == '-') {
			int num1 = nums.top();
			nums.pop();
			int num2 = nums.top();
			nums.pop();
			ans = num2 - num1;
		}
		else {
			ans = nums.top();
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;
	//string exp = "3+2*2/2-3";
	//string exp = "1 + 1 ";
	//string exp = "2*3+4";
	string exp = "1*2-3/4+5*6-7*8+9/10";
	//string exp = "2-3+4";

	
	cout << sol.calculate(exp);

	cin >> c;
}




