#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:

	long long traverse(long long n) {
		if (n == 1) return 0;
		if (n == 2) return 1;
		if (n == 3) return 2;

		long long min = LLONG_MAX;

		if (n % 2 == 0) {  // even
			long long step = traverse(n / 2) + 1;
			if (step < min) min = step;
		}
		else {				// odd
			long long step = traverse(n - 1) + 1;
			if (step < min) min = step;

			step = traverse(n + 1) + 1;
			if (step < min) min = step;
		}
		return min;
	}

	int integerReplacement(int n) {
		return traverse(n);
	}

};

int main() {
	char c;
	Solution sol;

	cout << sol.integerReplacement(2147483647);

	cin >> c;
}

/*
class Solution {
public:

	void reEvaluate(vector<int> &v, int n, int st) {
		int p = st;
		if (p % 2 == 0) {  // even
			// check /2
			if (v[p / 2] != 0 && v[p] > v[p / 2] + 1) {
				v[p] = v[p / 2] + 1;

				for (int i = p*2; i <= n; i *= 2) {
					if (v[i] == 0) {
						v[i] = v[i / 2] + 1;
					}
					else {
						if (v[i] > v[i / 2] + 1) {
							v[i] = v[i / 2] + 1;
							reEvaluate(v, n, i - 1);
							reEvaluate(v, n, i + 1);
						}
					}
				}
			}
		}
		else {				// odd
			if (v[p - 1] != 0 ) {

			}
		}
	}

	int integerReplacement(int n) {
		vector<int> v(n+1, 0);

		if (n <= 1) return 0;
		if (n == 2) return 1;

		v[1] = 0;

		// till no empty ..
		{
			int st = 2;
			if (st % 2 == 0) {  // even
				for(int i = )
			}
			else {				// odd

			}



		}

		v[2] = 2;


	}
};

*/