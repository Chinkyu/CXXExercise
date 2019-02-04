#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int product(int num1, int num2) {
	return num1 * num2;
}

double geometricMean(const vector<int>& nums) {
	double mult = accumulate(nums.begin(), nums.end(), 1, product);
	return pow(mult, 1.0 / nums.size());
}


int main() {
	char c;
	vector<int> n = { 1, 2, 3, 4, 5 };

	cout << "geometric mean = " << geometricMean(n);

	cin >> c;
}