// 답 봤음... 누적 Array를 사용하는 솔루션으로 
// 이렇게 생각 하기가 힘듬........   안하면  Timeout.. 

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


class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		int* temp = new int[122]{ 0 };
		for (int i = 0; i < ages.size(); i++)
		{
			temp[ages[i]]++;
		}

		for (int i = 1; i < 122; i++)
		{
			temp[i] = temp[i] + temp[i - 1];
		}

		int res = 0;
		for (int i = 0; i < ages.size(); i++)
		{
			if (ages[i] > 14)
				res += (temp[ages[i]] - temp[(int)(0.5*ages[i]) + 7]) - 1;
		}

		return res;
	}
};

class _Solution {
public:

	bool isRequestable(int ax, int ay) {
		if (ay <= 0.5 * ax + 7) return false;
		if (ay > ax) return false;
		if (ay > 100 && ax < 100) return false;
		return true;
	}

	int _numFriendRequests(vector<int>& ages) {  // timeout
		set<set<int>> s;
		int ans = 0;

		for (int i = 0; i < ages.size(); ++i) {
			for (int j = 0; j < ages.size(); ++j) {
				if (i == j) continue;
				if (isRequestable(ages[i], ages[j]) == true)  ans++;
			}
		}
		return ans;
	}

	int numFriendRequests(vector<int>& ages) {  // timeout
		set<set<int>> s;
		int ans = 0;

		sort(ages.begin(), ages.end(), [](int l, int r) {return l > r; });

		for (int i = 0; i < ages.size(); ++i) {
			int j = i+1;
			while (j - 1 >= 0 && ages[i] == ages[j - 1]) j--;
			for (; j < ages.size(); ++j) {
				if (i == j) continue;
				if (isRequestable(ages[i], ages[j]) == true)  ans++;
			}
		}
		return ans;
	}

};

int main() {
	char c;

	Solution sol;

	vector<int> ages = { 16, 17, 18 };

	cout << sol.numFriendRequests(ages);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}