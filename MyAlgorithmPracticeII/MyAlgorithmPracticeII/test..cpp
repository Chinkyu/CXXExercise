// It experience timeout... !!!  => NOT Solved..!
//:: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution1 {
public:
	// compare function for send pair
	static bool sortbyredix(const int& a, const int& b) {
		string lhs = to_string(a);
		string rhs = to_string(b);

		// it is really excellent
		// From this way, 30 < 3 == true;
		return (lhs + rhs > rhs + lhs);
	}


	string largestNumber(vector<int>& nums) {
		string res;
		sort(nums.begin(), nums.end(), sortbyredix);

		for (auto n : nums) {
			res.append(to_string(n));
		}

		// exception procession
		// remove front 0
		while (res.length() > 1 && res[0] == '0') res.substr(0);

		return res; //  to_string(stol(res.c_str()));
	}
};

class Solution {
public:
	// compare function for send pair
	static bool sortbyredix(const string& a, const string& b) {

		// it is really excellent
		// From this way, 30 < 3 == true;
		return (a + b > b + a);
	}


	string largestNumber(vector<int>& nums) {
		string res;
		vector<string> snums;

		for (auto e : nums) {
			snums.push_back(to_string(e));
		}

		sort(snums.begin(), snums.end(), sortbyredix);

		for (auto n : snums) {
			res.append(n);
		}

		// exception procession
		// remove front 0
		while (res.length() > 1 && res[0] == '0') res.substr(0);

		return res; //  to_string(stol(res.c_str()));
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> n = { 10, 2 }; // { 999999998, 999999997, 999999999 };

	//	cout << (to_string(30) > to_string(3)) << " ";

	cout << sol.largestNumber(n) << endl;

	cin >> c;
}