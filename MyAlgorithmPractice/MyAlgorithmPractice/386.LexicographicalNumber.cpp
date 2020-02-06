#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void traverse(vector<int> &v, int num, int last) {

		v.push_back(num);
		cout << num << " ";
		for (int i = 0; i <= 9; ++i) {
			if (num * 10 + i <= last) {
				traverse(v, num * 10 + i, last);
			}
		}
	}

	vector<int> lexicalOrder(int n) {
		vector<int> v;

		for (int i = 1; i <= 9; ++i) {
			if (i <= n) {
				traverse(v, i, n);
			}
		}
		return v;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> v = sol.lexicalOrder(125);

	cin >> c;
}