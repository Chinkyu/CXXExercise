#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static const int MAX_SUM = 999999;
	int min_sum;
	vector<int> min_table;

	int minimumTotal(vector<vector<int>>& triangle) {
		min_sum = MAX_SUM;
		min_table.resize(triangle.size());

		min_table[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); ++i) {
			for (int j = i; j >= 0; --j) {
				if (j == 0) { // no left
					min_table[j] = min_table[j] + triangle[i][j];

				}
				else if (j == i) {// no right
					min_table[j] = min_table[j-1] + triangle[i][j];
				}
				else {
					min_table[j] = (min_table[j - 1] > min_table[j]) ? min_table[j] + triangle[i][j] : min_table[j - 1] + triangle[i][j];
				}			
			}
		}
		
		for (int i = 0; i < triangle.size(); ++i) {
			if (min_table[i] < min_sum) min_sum = min_table[i];
		}
		return min_sum;
	}
};

// very slow solution ....-> 
class _Solution {
public:
	static const int MAX_SUM = 999999;
	int min_sum;

	void traverse(vector<vector<int>>& triangle, int level, int idx, int sum) {

		if (level + 1 >= triangle.size()) {
			//sum += (triangle[level][idx] > triangle[level][idx + 1]) ? triangle[level][idx + 1] : triangle[level][idx];
			sum += triangle[level][idx];
			if (min_sum > sum) min_sum = sum;
			return;
		}
		
		//if (sum + triangle[level][idx] < min_sum) 
		{
			traverse(triangle, level + 1, idx, sum + triangle[level][idx]);
			traverse(triangle, level + 1, idx + 1, sum + triangle[level][idx]);
		}
	}

	int minimumTotal(vector<vector<int>>& triangle) {
		min_sum = MAX_SUM;
		traverse(triangle, 0, 0, 0);
		return min_sum;
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> tri = {
		{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}
		//		{-1},{-2,-3}
		//{-1}, {2, 3}, {1, -1, -3}
	};


	cout << sol.minimumTotal(tri);


	cin >> c;
}