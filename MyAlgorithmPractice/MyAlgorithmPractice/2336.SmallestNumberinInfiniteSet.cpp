// easy
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

class SmallestInfiniteSet {
public:
	set<int> rs;
	int smallest = 1;

	SmallestInfiniteSet() {
		rs.clear();
	}

	int popSmallest() {
		int pre_smallest = smallest;
		rs.insert(smallest);
		
		for (int i = smallest + 1;; ++i) {
			if (rs.find(i) == rs.end()) {
				smallest = i;
				break;
			}
		}
		return pre_smallest;
	}

	void addBack(int num) {
		if (num < smallest) {
			smallest = num;
		}
		rs.erase(num);
	}
};

int main() {
	char c;

	Solution sol;

	string start = "_L__R__R_", target = "L______RR";
	//string start = "_R", target = "R_";

	cout << sol.canChange(start, target);

	cin >> c;

}