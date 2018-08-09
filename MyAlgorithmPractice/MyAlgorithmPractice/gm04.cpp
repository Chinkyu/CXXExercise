#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string line;
	string str;

	while (getline(cin, line)) {
		istringstream input(line);

		int x, y;
		getline(input, str, ',');
		x = stoi(str);
		getline(input, str, ';');
		y = stoi(str);

		vector<vector<int>> map(x, vector<int> (y, '.'));

		getline(input, str);
		int k = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				map[i][j] = str[k++];
			}
		}

		// account number
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (map[i][j] == '.') {
					map[i][j] = '0';

					for (int k = -1; k <= 1; k++) {
						for (int l = -1; l <= 1; l++) {
							if (i + k < 0 || i + k >= x) continue;
							if (j + l < 0 || j + l >= y) continue;
							if (map[i + k][j + l] == '*') map[i][j]++;
						}
					}
				}
			}
		}

		// print map
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << (char)map[i][j];
			}
		}
	}
}
