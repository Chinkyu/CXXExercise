#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<long long> cows(n, 0);
	vector<long long> candy(m, 0);
	vector<long long> height(m, 0);

	for (int i = 0; i < n; ++i) cin >> cows[i];
	for (int i = 0; i < m; ++i) cin >> candy[i];

	int maxCowidx = -1;
	long long maxCow = 0;
	for (int i = 0; i < n; ++i) {
		if (cows[i] >= maxCow) {
			maxCow = cows[i];
			maxCowidx = i;
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i <= maxCowidx; ++i) {
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

	// pause
	char c;
	cin >> c;
}