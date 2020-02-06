#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
 class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

class Solution {
public:
	void parse(string s, int &idx, NestedInteger &ni) {
		int n = s.size();
		NestedInteger *pn = &ni;
		bool isNegative = false;
		bool isNumber = false;
		int num = 0;

		while (idx < n) {
			switch (s[idx]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				num *= 10;
				num += s[idx] - '0';
				isNumber = true;
				break;
			case '[':
				pn = new NestedInteger();
				parse(s, ++idx, *pn);
				break;
			case '-':
				isNegative = true;
				break;
			case ',':
				if (isNumber == true) {
					if (isNegative) num *= -1;
					ni.add(num);
					num = 0;
				}
				else {
					ni.add(*pn);
				}

				isNegative = false;
				isNumber = false;
				break;
			case ']':
				idx++;
				return;
				break;
			}
			idx++;
		}

		if (isNumber == true) {
			if (isNegative) num *= -1;
			ni.add(num);
			num = 0;
		}

		//ni = *pn;
	}

	NestedInteger deserialize(string s) {
		NestedInteger ni;
		int i = 0;
		
		parse(s, i, ni);

		return ni;
	}
};

int main() {
	Solution sol;
	char c;

	string s = "324";
	NestedInteger ni = sol.deserialize(s);



	cin >> c;
}