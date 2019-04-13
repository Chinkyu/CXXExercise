#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		string::iterator itr = str.begin();
		int sign = 1;
		long long num = 0;

		// remove white space
		while (*itr == ' ') itr++;

		// 
		if (*itr == '-') {
			sign = -1;
			itr++;
		}
		else if (*itr == '+') {
			sign = 1;
			itr++;
		}

		for (; itr != str.end(); ++itr) {
			if ('0' <= *itr && *itr <= '9') {
				num *= 10;
				num += *itr - '0';

				if (num*sign >= INT_MAX) return INT_MAX;
				if (num*sign <= INT_MIN) return INT_MIN;
			}
			else {
				break;
			}
		}

		return num * sign;
	}
};


int main() {
	char c;
	string input;
	Solution sol;

//	while (true) {
//		cout << "Type string:";
//		cin >> input;
		cout << sol.myAtoi("-91283472332");
//	}

	cin >> c;
}