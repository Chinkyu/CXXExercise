//  답봤음 : 의외로 이렇게 풀리는데 맞나?? -  얼탱이가 없네... 
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
#include <cmath>

using namespace std;

class _Solution {
public:
	vector<long long> maximumEvenSplit(long long n) {
		if (n % 2) // odd
			return {};

		vector<long long> ans;
		long long i = 2;
		long long crSum = 0;

		while ((crSum + i) <= n)
		{
			ans.push_back(i);
			crSum += i;
			i += 2;
		}

		// add remaining difference to the last value in answer list
		int sz = ans.size();
		ans[sz - 1] += (n - crSum);
		return ans;
	}
};

class Solution {
public:
	vector<long long> maximumEvenSplit(long long n) {
		vector<long long> ans;

		if (n % 2 == 1) return ans;

		long long num = 0, sum = 0;
		long long inc = 2;

		while (sum + num + 2 <= n) {
			num += 2;
			ans.push_back(num);
			sum += num;
		}
		
		if (sum < n) {
			ans[ans.size() - 1] += n - sum;
		}

		return ans;
	}
};



int main() {
	char c;

	Solution sol;

	vector<long long> ans = sol.maximumEvenSplit(28);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;

}