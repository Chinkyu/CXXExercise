#include <iostream>
#include <vector>
#include <list>

/*
Explanation
first is first item in the remaining array
1,2,3,4,5,6,7,8,9
2,4,6,8
2,6
6

step means how many rounds of elimination is done

And based on the direction of elimination and the length of remaining number, sometimes we need to get rid of the first item.
we do first += 1<<step

Complexity
Time complexity should be O(logN) since every iteration does n = n>>1

*/

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		int first = 1;

		for (int step = 0; n != 1; n = n >> 1, step++) {
			if (step % 2 == 0 || n % 2) first += 1 << step;
		}

		return first;
	}



	int _lastRemaining(int n) {
		list<int> l;

		if (n == 1) return 1;

		// make list 
		for (int i = 2; i <= n; i += 2) l.push_back(i);

		if (l.size() == 1) return l.front();

		while (l.size() > 1) {
			// go back 
			list<int>::iterator it = prev(l.end());
			do {
				it = l.erase(it);
				if (it == l.begin() || l.size() <= 1) {
					break;
				}
				--it;
				if (it == l.begin()) {
					break;
				}
				--it;
				if (it == l.begin()) {
					it = l.erase(it);
					break;
				}
			} while (it != l.begin());

			if (l.size() == 1) return l.front();
			// go front
			it = l.begin();
			do {
				it = l.erase(it);
				if (it == l.end() || l.size() <= 1) {
					break;
				}
				++it;
				if (it == l.end()) {
					break;
				}
			} while (it != l.end());
		}
		return l.front();
	}
};

int main() {
	char c;
	Solution sol;

	for (int i = 1; i < 100; ++i) {
		cout << sol.lastRemaining(i) << endl;
	}
	cin >> c;
	return 0;
}
