#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define MAX_LEN  500

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string ina, string inb) {
		string str;
		string ans;
		int a, b, c, d;

		istringstream inA(ina), inB(inb);

		getline(inA, str, '+');
		a = stoi(str);
		getline(inA, str, ';');
		b = stoi(str);

		getline(inB, str, '+');
		c = stoi(str);
		getline(inB, str, ';');
		d = stoi(str);

		char c_ans[MAX_LEN];
		sprintf_s(c_ans, "%d+%di", (a*c - b * d), (a*d + b * c));
		ans.append(c_ans);

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string l = "1+1i";
	string r = "1+1i";

	cout << sol.complexNumberMultiply(l, r);

	cin >> c;
}