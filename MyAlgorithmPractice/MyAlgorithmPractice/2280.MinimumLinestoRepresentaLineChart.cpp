// double 로도 풀려야 한다고 생각함.
// 답음  if((long long int)slope[0] * prevSlope[1] != (long long int)slope[1] * prevSlope[0]) 을 가지고
// fixed point checking  하기를 원함. 

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	int _minimumLines(vector<vector<int>>& stockPrices) {

		int dchange = 1;
		float degree = 0;

		if (stockPrices.size() < 2) return 0;

		sort(stockPrices.begin(), stockPrices.end());

		degree = ((float)stockPrices[1][1] - stockPrices[0][1]) / ((float)stockPrices[1][0] - stockPrices[0][0]);
		for (int i = 2; i < stockPrices.size(); ++i) {
			float ndegree = ((float)stockPrices[i][1] - stockPrices[i-1][1]) / ((float)stockPrices[i][0] - stockPrices[i-1][0]);
			if (degree != ndegree) {
				//cout << i << " " << degree - ndegree << " " << degree << " " << ndegree << endl;
				degree = ndegree;
				dchange++;
			}
		}
		return dchange;
	}

	int minimumLines(vector<vector<int>>& stockPrices) {

		int dchange = 1;
		double degree = 0;

		if (stockPrices.size() < 2) return 0;

		sort(stockPrices.begin(), stockPrices.end());

		degree = ((double)stockPrices[1][1] - stockPrices[0][1]) / ((double)stockPrices[1][0] - stockPrices[0][0]);
		for (int i = 2; i < stockPrices.size(); ++i) {
			double ndegree = ((double)stockPrices[i][1] - stockPrices[i - 1][1]) / ((double)stockPrices[i][0] - stockPrices[i - 1][0]);
			if (degree != ndegree) {
				cout << i << " " << degree - ndegree << " " << degree << " " << ndegree << endl;
				degree = ndegree;
				dchange++;
			}
		}
		return dchange;
	}
};



int main() {
	char c;

	Solution sol;

	//vector<vector<int>> stockPrices = {{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1}};
	//vector<vector<int>> stockPrices = {{72, 98}, {62, 27}, {32, 7}, {71, 4}, {25, 19}, {91, 30}, {52, 73}, {10, 9}, {99, 71}, {47, 22}, {19, 30}, {80, 63}, {18, 15}, {48, 17}, {77, 16}, {46, 27}, {66, 87}, {55, 84}, {65, 38}, {30, 9}, {50, 42}, {100, 60}, {75, 73}, {98, 53}, {22, 80}, {41, 61}, {37, 47}, {95, 8}, {51, 81}, {78, 79}, {57, 95}};
	vector<vector<int>> stockPrices = { {1, 1}, {500000000,499999999}, {1000000000,999999998} };
	cout << sol.minimumLines(stockPrices);

	cin >> c;

}