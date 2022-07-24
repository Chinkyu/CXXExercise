#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void recursion(int idx, vector<int> input, vector<int> permu, vector<vector<int>> &ans) {
		int len = input.size();

		if (idx == len - 1) {
			// add new result
			ans.push_back(permu);
			return;
		}


	}


	void permutation(vector<int> input, vector<vector<int>> &output) {

	}



	void combRecursion(int idx, vector<int> &input, vector<int> cmbArray) {
		int len = input.size();

		if (idx == len) {
			for (auto it : cmbArray) {
				cout << " " << it;
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < len; ++i) {
			vector<int> temp = cmbArray;
			temp.push_back(input[i]);
			combRecursion(idx + 1, input, temp);
		}
	}


	void combination(vector<int> input) {

		vector<int> temp;

		combRecursion(0, input, temp);

	}
};

int main() {
	Solution sol;
	char c;

	vector<int> input = { 1,2,3 };
	vector<vector<int>> output;

	//sol.permutation(input);
	sol.combination(input);

	cin >> c;
}
