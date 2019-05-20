#include <iostream>
#include <vector>

using namespace std;

// X0 으로 메핑해서 substring 으로 처리하기..  로 구현해 보자... 안되서
// 답보고 빼낌... 다시해봐야함. => 신기함... !!!!!!!!!!!!!!!!!!!!!!
// XXXX 

class Solution {
public:
	int numDecodings1(string s) {
		int i;
		int n = s.size();
		vector<int> count(n, 1);
		//int ci = 0, cii = 0;

		if (s[0] == '0') return 0;

		for (i = 0; i < n-1; ++i) {	
			if (s[i] == '0') return 0;
			if (s[i + 1] == '0') {
				if (s[i] >= '3') return 0;

				if (i - 1 >= 0) {
					count[i] = count[i + 1] = count[i - 1];
				}
				else {
					count[i] = count[i + 1] = 1;
				}
				i++;
				continue;
			} else if (s[i] == '1' ||
				      (s[i] <= '2' && s[i + 1] <= '6')) {
				count[i + 1] += count[i - 1];// *2;// +1;
				//cii = ci + 1;
			}
			count[i + 1] = (count[i + 1] > count[i]) ? count[i + 1] : count[i];
			//cii = (cii > ci) ? cii : ci;
			//if (s[i + 1] == '0') count[i + 1]--;


		}
		if (i < n && s[i] == '0') return 0;

		return count[n - 1];
	}

	int numDecodings(string s) {
		int n = s.size();
		vector<int>store_val(n + 1);
		store_val[n] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '0')
				store_val[i] = 0;
			else
			{
				store_val[i] = store_val[i + 1];
				if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
					store_val[i] += store_val[i + 2];
			}
		}
		return s.empty() ? 0 : store_val[0];
	}
};

int main() {
	Solution sol;
	char c;
	//string s = "226";
	string s = "1212";//2012";

	cout << sol.numDecodings(s);

	cin >> c;
}