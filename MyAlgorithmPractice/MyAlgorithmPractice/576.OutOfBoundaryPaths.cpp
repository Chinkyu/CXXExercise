#include <iostream>
#include <vector>

using namespace std;

#define MAX_MEMO 60


// Brute force make timeout... 
class _Solution {
public:
	int total = 0;
	int gm, gn, gN;
	long long memo[MAX_MEMO][MAX_MEMO][MAX_MEMO];
	void traverse( int step, int i, int j) {

		if (step > gN) return;
		if (i < 0 || gm <= i) {
			total++;
			return;
		}
		if (j < 0 || gn <= j) {
			total++;
			return;
		}
		
		if (memo[i][j][step] != -1) {
			total = memo[i][j][step];
			return;
		}
		// move 4 direction
		traverse(step + 1, i - 1, j);
		traverse(step + 1, i, j - 1);
		traverse(step + 1, i + 1, j);
		traverse(step + 1, i, j + 1);

		memo[i][j][step] = total;
	}


	int findPaths(int m, int n, int N, int i, int j) {

		total = 0;
		gm = m;
		gn = n;
		gN = N;

		traverse(0, i, j);
		return total;

	}
};

// memoization solution 



int main() {
	char c;
	Solution sol;

	//cout << sol.findPaths(2, 2, 2, 0, 0);
	//cout << sol.findPaths(1, 3, 3, 0, 1);
	cout << sol.findPaths(8, 7, 10, 1, 5);



	cin >> c;
}
