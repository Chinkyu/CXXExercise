// 앞에서 하다가 해매서 뒤에서 하는것으로 해서 해결함. 
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
	// Method 1   not working.. 
	int _secondsToRemoveOccurrences(string s) {
		int l = s.size();

		int firstZero = -1, zeroNum = 0;
		int firstContinuousZero = 0;
		for (int i = 0; i < l; ++i) {
			if (firstZero == -1 && s[i] == '0') {
				firstZero = i;
				for (int j = i; j < l; ++j) {
					if (s[j] == '0') {
						firstContinuousZero++;
					}
					else {
						break;
					}
				}
			}
			if (s[i] == '0') zeroNum++;
		}

		int ans = 0;
		
		if (firstZero != -1) {
			ans = (l - firstZero) - zeroNum;
		}

		// need count first continuous zero
		if (ans != 0 && firstContinuousZero > 1) ans += firstContinuousZero - 1;

		return ans;
	}

	int secondsToRemoveOccurrences(string s) {
		vector<int> v;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1') v.push_back(i);
		}

		int count = 0;

		int start = 0, end = v.size() - 1;
		//bool startFlag = true;
		for (int i = end; i >= start; --i) {
			if (v[i] == i) {
				end = i - 1;
			}
			else {
				break;
			}
		}

		while (start <= end) {

			bool startFlag = true;
			for (int i = end; i >= start; --i) {
				if (i > 0 && v[i] > i && v[i-1] != v[i] - 1) v[i]--;
				else if (i == 0 && v[i] > i) v[i]--;

				if (v[i] == i) {
					start = i + 1;
					break;
				}
			}
			count++;
		}

		return count;
	}
};

int main() {
	char c;

	Solution sol;

	//string s = "abc";
	string s =   "11100"; // "0110101"; //
	
	cout << sol.secondsToRemoveOccurrences(s);

	cin >> c;
}