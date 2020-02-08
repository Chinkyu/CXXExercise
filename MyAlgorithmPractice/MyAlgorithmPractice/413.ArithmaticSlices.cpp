#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int l = A.size();

		if (l <= 2) return 0;
		int i = 0;
		int st = 0, ed = 0;
		int g = A[1] - A[0];
		i = 3;
		do {
			if (A[i] - A[i - 1] != g) {
				ed = i-1;
				cout << st << " " << ed << endl;

				st = i - 1;
				g = A[i] - A[i - 1];
			}

			i++;

		} while (i < l);

		if (l-1 - st >= 3) {
			ed = l - 1;
			cout << st << " " << ed << endl;
		}

	}
};

int main() {
	char c;
	Solution sol;

	vector<int> v = { 1, 2, 3, 4 , 5,7,9,11,12 };
	cout << sol.numberOfArithmeticSlices(v);
	cin >> c;
}