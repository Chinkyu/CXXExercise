//		if (num != 1) {  넣고는 타임아웃안됬는데.. 꽁수 있넉 같다.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


// timeout solution.. escape with 		if (num != 1) {
class ProductOfNumbers {
public:
	vector<int> product;
	vector<int> nums;
	int n = 0;
	ProductOfNumbers() {
		product.clear();
		nums.clear();
		n = 0;
	}

	void add(int num) {

		if (num != 1) {
			for (int i = 0; i < n; ++i) product[i] *= num;
		}
		product.push_back(num);
		nums.push_back(num);
		n++;
	}

	int getProduct(int k) {
		return (product[n - k]);
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25 } };

	vector<int> ans = sol.corpFlightBookings(bookings, 5);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}