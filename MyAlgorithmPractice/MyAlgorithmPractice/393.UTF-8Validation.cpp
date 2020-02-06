#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int l = data.size();

		for (int i = 0; i < l; ++i) {

			// define size
			if ((data[i] & 0xF8) == 0xF0) {
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
			}
			else if ((data[i] & 0xF0) == 0xE0) {
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
			}
			else if ((data[i] & 0xE0) == 0xC0) {
				if (++i < l && (data[i] & 0xC0) == 0x80); else return false;
			}
			else if ((data[i] & 0x80) == 0x00) {

			}
			else {
				return false;
			}

		}
		return true;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> data = { 197, 130, 1 };
	cout << sol.validUtf8(data);

	cin >> c;
}