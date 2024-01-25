// easy
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
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		int l = asteroids.size();
		long long pMass = mass;

		sort(asteroids.begin(), asteroids.end());

		for (auto it : asteroids) {
			if (pMass >= it) {
				pMass += it;
			}
			else {
				return false;
			}
		}

		return true;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> asteroids = { 4,9,23,4 };

	cout << sol.asteroidsDestroyed(5, asteroids);

	cin >> c;
}