// Lee Code Accepted 
#include <iostream>
#include <string>

using namespace std;

//int max(int x, int y) { return (x > y) ? x : y; }

class Solution {
public:
	string longestPalindrome1(string &str) {
		int maxLength = 1;

		int start = 0; 
		int len = str.length();

		int low, high;

		// iterate for all position
		for (int i = 1; i < len; i++) {

			// find even palindrom
			low = i - 1;
			high = i;
			while (low >= 0 && high < len && str[low] == str[high]) {
				if (high - low + 1 > maxLength) {
					start = low;
					maxLength = high - low + 1;
				}
				low--;
				high++;
			}

			// find odd palindrom
			low = i - 1;
			high = i + 1;
			while (low >= 0 && high < len && str[low] == str[high]) {
				if (high - low + 1 > maxLength) {
					start = low;
					maxLength = high - low + 1;
				}
				low--;
				high++;
			}
		}

		return str.substr(start, maxLength);
	}
};

int main() {
	int i;
	Solution sol;
	string s("BBABCBCAB"); //  "GEEKSFORGEEKS");
	cout << "the length of the LPS is " << sol.longestPalindrome1(s);

	cin >> i;

}