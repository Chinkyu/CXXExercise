//	리커시브로 풀면 타임아웃... 순열을 찾아서 풀었음
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
#include <cmath>

using namespace std;


// n 이 늘어나면서   0 -> 0,1    1->1  로 바뀌니까..
// [1] = [i-1][0],    [0] = [i-1][0] + [i-1][1]  로 계산 됨 
class Solution {
public:
	long long getOneside(int n) {
		vector<int> v(2, 1);

		for (int i = 2; i <= n; ++i) {
			vector<int> tv = v;
			v[1] = tv[0] % (1000000007);
			v[0] = (tv[0] + tv[1]) % (1000000007);
		}

		return v[0] + v[1];
	}

	int countHousePlacements(int n) {
		long long oneside = getOneside(n);

		//cout << "oneside" << oneside << endl;
		// two side??
		return (oneside * oneside) % (1000000007);
	}
};


// timeout solution 
class _Solution {
public:
	vector<int> house;
	int oneside = 0;
	void traverse(int n, int idx, int prev) {
		
		if (n == idx) {
			oneside++;
			return;
		}

		house[idx] = 0;
		traverse(n, idx + 1, 0);

		if (prev != 1) {  // can't put 1 this place
			house[idx] = 1;
			traverse(n, idx + 1, 1);
		}

	}


	int countHousePlacements(int n) {
		house = vector<int>(n, 0);
		oneside = 0;

		traverse(n, 0, 0);

		cout << "oneside" << oneside << endl;
		// two side??
		return (oneside * oneside) % (1000000007);


	}
}; 

int main() {
	char c;

	Solution sol;
	cout << sol.countHousePlacements(7);

	cin >> c;
}




