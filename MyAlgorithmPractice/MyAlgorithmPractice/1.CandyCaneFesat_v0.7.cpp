#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	long long n, m;

	cin >> n >> m;

	vector<long long> cows(n, 0);
	vector<long long> candy(m, 0);
	vector<long long> height(m, 0);

	for (long long i = 0; i < n; ++i) cin >> cows[i];
	for (long long i = 0; i < m; ++i) cin >> candy[i];

	long long maxCowidx = -1;
	long long maxCow = 0;
	vector<long long> validCow(n, 0);
	for (long long i = 0; i < n; ++i) {
		if (maxCow <= cows[i]) {
			maxCow = cows[i];
			validCow[i] = 1;
			maxCowidx = i;
		}
		else {
			validCow[i] = 0;
		}
	}

	for (long long j = 0; j < m; ++j) {
		for (long long i = 0; i <= maxCowidx; ++i) {

			if (validCow[i] == 0) continue;

			if (candy[j] == height[j]) break;

			if (candy[j] > height[j] && cows[i] > height[j]) {
				long long preheight = height[j];
				height[j] = cows[i];

				long long eat = (cows[i] < candy[j]) ? cows[i] - preheight : candy[j] - preheight;
				cows[i] += eat;
			}
		}
	}

	for (auto &it : cows) {
		cout << it << endl;
	}

}