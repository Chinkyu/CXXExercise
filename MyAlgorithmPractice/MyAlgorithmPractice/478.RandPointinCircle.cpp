#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

class Solution {
public:
	double r;
	double x;
	double y;

	Solution(double radius, double x_center, double y_center) {
		srand(time(NULL));
		r = radius;
		x = x_center;
		y = y_center;
	}

	vector<double> randPoint() {
		double dx, dy;
		vector<double> ans;

		do {
			dx = ((double)rand() / (RAND_MAX))*r;
			dy = ((double)rand() / (RAND_MAX))*r;

		} while (sqrt(pow(dx, 2) + pow(dy, 2)) > r);

		ans.push_back(x + dx);
		ans.push_back(y + dy);
		return ans;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */