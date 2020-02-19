#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int factorial(int n) {
		int ans = 0;

		for (int i = n; i > 0; --i) ans += i;
		return ans;
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		int ans = 0;
		int l = A.size();

		if (l <= 2) return 0;
		int i = 0;
		int st = 0, ed = 0;
		int g = A[1] - A[0];
		i = 2;
		do {
			if (A[i] - A[i - 1] != g) {
				ed = i-1;
				//cout << st << " " << ed << endl;
				ans += factorial(ed - st - 1);
				st = i - 1;
				g = A[i] - A[i - 1];
			}

			i++;

		} while (i < l);

		if (l-1 - st >= 2) {
			ed = l - 1;
			//cout << st << " " << ed << endl;
			ans += factorial(ed - st - 1);
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> v = { 1, 2, 3 , 4 }; // , 5, 7, 9, 11, 12
	cout << sol.numberOfArithmeticSlices(v);
	cin >> c;
}