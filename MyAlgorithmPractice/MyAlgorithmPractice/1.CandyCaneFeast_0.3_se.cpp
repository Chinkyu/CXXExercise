#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, temp;
	cin >> n >> m;

	vector<int> cows(n, 0), candy(m, 0), height(m, 0);

	for (int i = 0; i < n; ++i) {
		cin >> cows[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> candy[i];
		height[i] = candy[i];
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (candy[i] == 0) {
				continue;
			}
			if (cows[j] > height[i] - candy[i]) { //cows can eat
				if (cows[j] >= height[i]) {
					cows[j] = cows[j] + candy[i];
					candy[i] = 0;
				}
				else {
					temp = candy[i];
					candy[i] = height[i] - cows[j];
					cows[j] = cows[j] + temp - candy[i];
				}
			}
			else {
				continue;
			}
		}
	}

	for (auto &it : cows) {
		cout << it << endl;
	}

	char c; 
	cin >> c;
	return 0;
}