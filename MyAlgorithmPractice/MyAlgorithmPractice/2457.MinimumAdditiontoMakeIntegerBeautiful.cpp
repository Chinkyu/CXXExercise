//   답봤고.. 맨 아래서 부터 0 로 만들면서 늘여가는것 같음 
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

typedef long long ll;
class Solution {
public:
	ll f(ll &n)// finding sum of all digits of number n
	{
		int s = 0;
		ll m = n;
		while (m != 0)
		{
			ll r = m % 10;
			s += r;
			m /= 10;
		}
		return s;
	}
	long long makeIntegerBeautiful(long long n, int target) {
		ll x = f(n);
		if (x <= target)
			return 0 * 1LL;
		ll cnt = 10;
		ll n1 = n;
		while (f(n1) > target)
		{
			ll r = n1 % cnt; // turning the rightmost zero in each iteration zero and then moving to left
			n1 = n1 - r + cnt;//subtracting r and turning rightmost digit zero basically adding cnt-r
			 // for converting rightmost digit zero in each iteration and moving to left
			cnt *= 10;
		}
		return n1 - n;// returning the value x here x=n1-n;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 14,2,11,19,6,18,8,20,11 }; // { 1, 5, 4, 2, 9, 9, 9 };
	//vector<int> nums = { 1, 5, 4, 2, 9, 9, 9 };

	cout << sol.maximumSubarraySum(nums, 6);
	cin >> c;
}