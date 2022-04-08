#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;



class Solution {
public:

	long long NCombination2(long long n) {
		if (n == 0) return 0;
		if (n == 1) return 0;
		if (n == 2) return 1;
		return (n*(n - 1)) / 2;
	}


	long long numberOfSubstrings(string s) {
		vector<int> cv('z' - 'a' + 1, 0);
		int n = s.size();

		// build count vector
		for (int i = 0; i < n; ++i) {
			cv[s[i] - 'a']++;
		}

		long long ans = 0;
		for (int i = 0; i < 'z' - 'a' + 1; ++i) {
			ans += NCombination2(cv[i]) + cv[i];
		}
		return ans;
	}
};



int main() {
	char c;
	Solution sol;

	//string s = "abcba"; // 7
	string s = "abacad"; // 9

	long long ans = sol.numberOfSubstrings(s);

	cout << "ans = " << ans << endl;

	cin >> c;
}