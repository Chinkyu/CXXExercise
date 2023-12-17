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
	int n; cin >> n;	string cow;

	cin >> cow;	//:: XXXX : 	for (int i = 0; i < n; i++) {
		cin >> candy[i];
		candy_remain[i] = candy[i];
	}
	for (int i = 0; i < n; ++i) {		int eat = 0;		for (int j = 0; j < m; ++j) {			if (candy[j] > cow[i] && cow[i] > height) {				eat += candy[j] - height;				candy_remain[j] -= candy[j] - height;			}			height = max(height, cow[i]);		}		cow[i] += eat;	}
	for (auto &it : cow) {
		cout << it << endl;
	}

}