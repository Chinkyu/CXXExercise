// It is not sorting. 
// It is lexicographical order.... => need to known what is lexicographical order 

#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
	string removeDuplicateLetters(string s) {
		string myS = s;
		string result;

		sort(myS.begin(), myS.end());

		char c = myS[0];
		result.push_back(c);
		for (int i = 1; i < myS.length(); i++) {
			if (c != myS[i]) {
				c = myS[i];
				result.push_back(c);
			}
		}
		
		return result;
	}
};


int main() {
	char c;
	Solution sol;
	string s = string("cbacdcbc");
	cout << sol.removeDuplicateLetters(s).c_str();

	cin >> c;
}