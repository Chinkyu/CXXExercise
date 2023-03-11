// 그냥 sequential을 하면   timeout이 나고
// binary search를 하면서 하면  됨..
// 일반적은 bsearch를 그냥 바로 선택 결정이 되는데... 이것은
// 지금것을 보고 다음것을 봐야 해서 이 부분만 조심 하면 됨. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class BinaryMatrix {
public:
	int get(int row, int col);
	vector<int> dimensions();
};


class Solution {
public:

	bool isAllZero(BinaryMatrix &binaryMatrix, vector<int> &size, int colum) {
		for (int j = 0; j < size[0]; ++j) { // raw
			if (binaryMatrix.get(j, colum) == 1) return false;
		}
		return true;
	}


	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		vector<int> size = binaryMatrix.dimensions();

		int st = 0, ed = size[1] - 1;

		while(st < ed) {
			int md = (st + ed) / 2;

			if (isAllZero(binaryMatrix, size, md) == true) {
				st = md + 1;
			}
			else {
				ed = md - 1;
			}
		}

		// st , ed
		if (isAllZero(binaryMatrix, size, st) == false) {
			return st;
		}
		else { // st column is all zero 
			if (st != size[1] - 1) return st + 1;  // is st is not the end 
		}
		
		return -1;
	}
};

// sequential.. 
class _Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		vector<int> size = binaryMatrix.dimensions();

		for (int i = 0; i < size[1]; ++i) { // column
			for (int j = 0; j < size[0]; ++j) { // raw
				if (binaryMatrix.get(j, i) == 1) return i;
			}
		}
		return -1;
	}
};

int main() {
	char c;

	Solution sol;

	string s1 = "lee(t(c)o)de)";
	//string s1 = "a)b(c)d";
	//string s1 = "))((";

	cout << sol.minRemoveToMakeValid(s1);

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}