#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int magicalString(int n) {
		vector<char> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(2);

		char toggle = 1;
		int i = 2;
		do{
			if (v[i++] == 1) {
				v.push_back(toggle);
			}
			else {
				v.push_back(toggle);
				v.push_back(toggle);
			}
			toggle = (toggle == 1) ? 2 : 1;
		} while (v.size() < n);

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] == 1) cnt++;
		}
		return cnt;
	}
};

int main() {
	char c;
	Solution sol;


	cout << sol.magicalString(7);
	cin >> c;
}