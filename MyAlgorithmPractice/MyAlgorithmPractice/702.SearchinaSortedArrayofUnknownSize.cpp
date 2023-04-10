//  Solve esaily... !! 
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

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
class ArrayReader {
public:
	int get(int index);
};


class Solution {
public:
	const int minv = -10000;
	const int maxv = 10000;
	const int obount = 0x7FFFFFFF;

	int search(const ArrayReader& reader, int target) {
		int sidx = 0;
		int eidx = maxv;

		while (sidx < eidx - 1) {
			int midx = (sidx + eidx) / 2;
			int midv = reader.get(midx);
			if (midv < target) {
				sidx = midx;
			}
			else if (target < midv || midv == obount) {
				eidx = midx;
			}
			else if (midv == target) {
				// find 
				return midx;
			}
		}

		if (reader.get(sidx) == target) return sidx;
		if (reader.get(eidx) == target) return eidx;
		return -1;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.champagneTower(100000009, 33, 17);

	cin >> c;
}