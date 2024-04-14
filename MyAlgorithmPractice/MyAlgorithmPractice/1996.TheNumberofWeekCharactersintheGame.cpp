// 답봤음 : 심박한 방법 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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

	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int l = properties.size();
		sort(properties.begin(), properties.end(), [](vector<int> &l, vector<int> &r) {
			return (l[0] != r[0]) ? l[0] > r[0] : l[1] < r[1];  //:: xXXX : l[1] < r[1] 이게 포인트
		});

		int ans = 0;

		int maxTillNow = INT_MIN;
		for (int i = 0; i < l; ++i) {
			if (maxTillNow > properties[i][1]) ans++;
			else maxTillNow = properties[i][1];
		}

		return ans;
	}
};


// timeout 
class _Solution {
public:

	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int l = properties.size();
		for (int i = 0; i < l; ++i) {
			properties[i].push_back(properties[i][0] + properties[i][1]);
		}

		sort(properties.begin(), properties.end(), [](vector<int> &l, vector<int> &r) {
			return l[2] < r[2];
		});

		int ans = 0;
//		for (int i = 0; i < l - 1; ++i) {
//			for (int j = i + 1; j < l; ++j) {
//				if (properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]) {
//					ans++;
//					break;
//				}
//			}
//		}

		// from backword
		for (int i = 0; i < l - 1; ++i) {
			for (int j = l-1; j >= i + 1; --j) {
				if (properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]) {
					ans++;
					break;
				}
			}
		}


		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> properties = {{7, 7}, {1, 2}, {9, 7}, {7, 3}, {3, 10}, {9, 8}, {8, 10}, {4, 3}, {1, 5}, {1, 5}};
	//{ {1, 5}, {10, 4}, {4, 3} };

	cout << sol.numberOfWeakCharacters(properties);

	cin >> c;
}