//  accu array 하나만 있으면 되는데.. 괜히 어렵게 생각했음... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

// timeout 
class _Solution {
public:
	long long getBeanNum(vector<int> & beans, int idx) {
		long long ans = 0;
		int pivot = beans[idx];

		for (int i = 0; i < beans.size(); ++i) {
			if (beans[i] < pivot) {
				ans += beans[i];
			}
			else {
				ans += beans[i] - pivot;
			}
		}
		return ans;
	}

	long long minimumRemoval(vector<int>& beans) {
		long long ans = LLONG_MAX;

		sort(beans.begin(), beans.end());

		for (int i = 0; i < beans.size(); ++i) {
			long long t_ans = getBeanNum(beans, i);
			cout << t_ans << " ";
			if (t_ans < ans) ans = t_ans;
		}
		return ans;
	}
};

class Solution {
public:

	long long minimumRemoval(vector<int>& beans) {
		long long ans = LLONG_MAX;
		long long l = beans.size();

		if (l == 1) return 0;

		sort(beans.begin(), beans.end());

		vector<long long> accu(beans.size(), 0);

		if (beans[0] == beans[l - 1]) return 0;

		accu[0] = beans[0];
		for (int i = 1; i < beans.size(); ++i) {
			accu[i] = accu[i - 1] + beans[i];
		}

		// No Zeroing... 
		ans = (accu[l - 1] - accu[0] - beans[0] * ((l - 1) - (0)));
		for (int i = 0; i < beans.size() - 1; ++i) {

			// till i accu,  accu(end) - accu(i + 1)  - Num of beans[i+1] --- 
			long long t_ans = 0; 
			if(i >= 0) t_ans += accu[i];
			t_ans += (accu[l - 1] - accu[i + 1] - beans[i + 1] * ((l - 1) - (i + 1)));
			cout << t_ans << " ";
			if (t_ans < ans) ans = t_ans;
		}
		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> beans = { 43,44,45,46,47 };

	cout << sol.minimumRemoval(beans);
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}