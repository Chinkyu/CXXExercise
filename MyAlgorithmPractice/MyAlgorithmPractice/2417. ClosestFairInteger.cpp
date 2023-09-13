//  답봤고.. :  string 으로  brute force 가 pass 나다니... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int closestFair(int n) {
		for (;; ++n) {
			string s = to_string(n);
			int sz = int(s.size());
			if (sz & 1) { // make it even length
				n = pow(10, sz++);
				s = to_string(n);
			}
			if (count_if(begin(s), end(s), [](char c) {return (c - '0') & 1; }) == sz / 2) {
				return n;
			}
		}
	}
};



class Solution {
public:
	bool isSameEvenOdd(int n) {
		int evennum = 0, oddnum = 0;

		while (n > 0) {
			int lastdigit = n % 10;
			if (lastdigit % 2 == 1) {
				oddnum++;
			}
			else {
				evennum++;
			}
			n = n / 10;
		}

		if (evennum == oddnum) return true;
		return false;
	}

	int closestFair(int n) {
		string s = to_string(n);
		int l = s.size();

		int ans = 0;
		if (l % 2 == 1) {  // odd
			for (int i = pow(10,l); ; ++i) {
				if (isSameEvenOdd(i)) return i;
			}
		}
		else {  // even
			for (int i = n; ; ++i) {
				if (isSameEvenOdd(i)) return i;
			}
		}
		return -1;
	}
};

int main() {
	char c;

	Solution sol;
	
	cout << sol.closestFair(99999999);

	cin >> c;
}