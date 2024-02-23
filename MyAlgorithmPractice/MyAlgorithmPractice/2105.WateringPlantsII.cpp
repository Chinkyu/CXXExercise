// 답봣음 : 왼쪽 오른쪽으로 파고 들면 된것 같음.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int n = plants.size();
		int count = 0;
		int start = 0;
		int end = n - 1;
		int aliceCC = capacityA;
		int bobCC = capacityB;
		while (start <= end) {

			if (start == end) {
				if (aliceCC >= bobCC) {
					if (aliceCC >= plants[start]) {
						aliceCC -= plants[start];
					}
					else {
						aliceCC = capacityA;
						count += 1;
					}
				}
				else {
					if (bobCC >= plants[end]) {
						bobCC -= plants[end];
					}
					else {
						bobCC = capacityB;
						count += 1;
					}
				}
				break;
			}
			if (aliceCC >= plants[start]) {
				aliceCC -= plants[start];
			}
			else {
				aliceCC = capacityA;
				aliceCC -= plants[start];
				count += 1;
			}
			if (bobCC >= plants[end]) {
				bobCC -= plants[end];
			}
			else {
				bobCC = capacityB;
				bobCC -= plants[end];
				count += 1;
			}


			start++;
			end--;
		}
		return count;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> candies = { 1, 2, 3, 2, 2, 2 }; //{ 1, 2, 2, 3, 4, 3 }; //

	cout << sol.shareCandies(candies, 3);

	cin >> c;
}