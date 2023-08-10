// �����  gcd�ΰ�츸 �ݺ����� �ǰ� �ƴϸ�.. �ȵȴٰ�.... 
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

//  gcd�� Ǭ�ٴµ�.....
class Solution {
public:
	long long makeSubKSumEqual(vector<int>& arr, int k) {
		long long ans = 0;
		long long n = arr.size();
		long long g = gcd(n, k);
		vector <long long> res;
		for (int i = 0; i < g; i++) {
			vector<long long> lol;
			for (int j = i; j < n; j += g) lol.push_back(arr[j]);
			sort(lol.begin(), lol.end());
			res.push_back(lol[lol.size() / 2]);
		}
		for (int i = 0; i < n; i++) ans += abs(res[i%g] - arr[i]);
		return ans;
	}
};

// �̰����� �ذ� ���� ����.. 
class Solution {
public:
	long long makeSubKSumEqual(vector<int>& arr, int k) {
		int l = arr.size();
		vector<long long> sum(l, 0);

		// first sum
		for (int i = 0; i < k; ++i) {
			sum[0] += arr[i];
		}

		long long total_sum = sum[0];
		for (int i = 1; i < l; ++i) {
			int add_idx = i + k - 1;
			add_idx = (add_idx >= l) ? add_idx - l : add_idx;
			sum[i] = sum[i - 1];
			sum[i] -= arr[i - 1];
			sum[i] += arr[add_idx];
			total_sum += sum[i];
		}

		long long avg = round(total_sum / l);
		long long ans = 0;
		for (int i = 0; i < l; ++i) ans += abs(avg - sum[i]);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> arr = { 2, 5, 5, 7 };

	cout << sol.makeSubKSumEqual(arr, 3);

	cin >> c;
}