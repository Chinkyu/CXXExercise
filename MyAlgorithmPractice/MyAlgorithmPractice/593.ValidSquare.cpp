//  아래 data일때 이상함... 그래서 그냥 감 
// 0,0  5,0  5,4  0,4

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:

	double distance(vector<int> &x, vector<int> &y) {

		return sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
	}

	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		double d1, d2, d3;
		d1 = distance(p1, p2);
		d2 = distance(p1, p3);
		d3 = distance(p1, p4);

		vector<double> d = { d1, d2, d3 };
		sort(d.begin(), d.end());

		double d4 = sqrt(pow(d[0], 2) + pow(d[1], 2));

		int a1 = d4 * 100000;
		int a2 = d[2] * 100000;

		//cout << a1 << endl;
		//cout << a2 << endl;

		return (a1 == a2);
	}
};

class ___Solution {
public:

	double distance(vector<int> &x, vector<int> &y) {

		return sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
	}

	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		double d1, d2, d3;
		d1 = distance(p1, p2);
		d2 = distance(p1, p3);
		d3 = distance(p1, p4);

		double d4 = sqrt(pow(d2, 2) + pow(d3, 2));

		int a1 = d1 * 100000;
		int a2 = d4 * 100000;

		//cout << a1 << endl;
		//cout << a2 << endl;

		return (a1 == a2);
	}
};


class __Solution {
	public:
		int d(vector<int>& p1, vector<int>& p2) {
			return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
		}
		bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
			unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
			return !s.count(0) && s.size() == 2;
		}
};


int main() {
	char c;
	Solution sol;

//	vector<int> p1 = { 0, 0 };
//	vector<int> p2 = { 1, 1 };
//	vector<int> p3 = { 1, 0 };
//	vector<int> p4 = { 0, 1 };

	vector<int> p1 = { 0, 0 };
	vector<int> p2 = { 5, 0 };
	vector<int> p3 = { 5, 4 };
	vector<int> p4 = { 0, 4 };


	cout << sol.validSquare(p1, p2, p3, p4);

	cin >> c;
}