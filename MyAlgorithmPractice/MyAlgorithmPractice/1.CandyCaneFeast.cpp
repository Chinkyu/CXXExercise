// ¥‰∫√¿Ω
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<int> cow(n, 0), candy(m, 0), height(m, 0);

	for (int i = 0; i < n; i++) {
		cin >> cow[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> candy[i];
	}

	for (int i = 0; i < n; ++i) {
		int eat = 0;
		for (int j = 0; j < m; ++j) {
			if (candy[j] - height[j] > 0 && cow[i] > height[j]) {
				int preHeight = height[j];
				height[j] = cow[i];

				int eat = (cow[i] < candy[j]) ? cow[i]-preHeight : candy[j]-preHeight;
				cow[i] += eat;
			}
		}
	}

	for (auto &it : cow) {
		cout << it << endl;
	}

	char c;
	cin >> c;
}