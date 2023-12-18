#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<int> cows(n, 0);
	vector<int> candyHeight(m, 0);
	vector<int> bottonHeight(m, 0);

	for (int i = 0; i < n; ++i) cin >> cows[i];
	for (int i = 0; i < m; ++i) cin >> candyHeight[i];

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (candyHeight[j] > bottonHeight[j] && cows[i] > bottonHeight[j]) {
				int prebottonHeight = bottonHeight[j];
				bottonHeight[j] = cows[i];

				int eat = (cows[i] < candyHeight[j]) ? cows[i] - prebottonHeight : candyHeight[j] - prebottonHeight;
				cows[i] += eat;
			}
		}
	}

	for (auto &it : cows) {
		cout << it << endl;
	}

	// pause
	//char c;
	//cin >> c;
}