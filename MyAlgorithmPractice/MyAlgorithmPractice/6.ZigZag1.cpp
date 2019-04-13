#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int size = s.size();
		string res;

		if (numRows < 2) return s;

		for (int i = 0; i < s.size(); i++) {
			if ((2 * numRows - 2)*i >= s.size()) break;
			res.push_back(s[(2 * numRows - 2)*i]);
		}

		for (int i = 1; i < numRows-1; i++) {
			for (int j = 0; j < s.size(); j++) {
				if (((2 * numRows - 2)*j + i) >= s.size()) break;
				res.push_back(s[(2 * numRows - 2)*j + i]);

				if (((2 * numRows - 2)*j + i + (2 * numRows - 2) - (i*2)) >= s.size()) break;
				res.push_back(s[((2 * numRows - 2)*j + i + (2 * numRows - 2) - (i * 2))]);
			}
		} 

		for (int i = 0; i < s.size(); i++) {
			if ((2 * numRows - 2)*i + (numRows -1) >= s.size()) break;
			res.push_back(s[(2 * numRows - 2)*i + (numRows - 1)]);
		}

		return res;
	}
};


int main() {
	char c;
	Solution sol;
	
	cout << sol.convert("ABCD",3) << endl;
//	cout << sol.convert("0123456789ABCDEFGHIJKL", 4) << endl;

//	cout << sol.convert("PAYPALISHIRING", 4) << endl;

	cin >> c;
}