// 한참 생각하다가... 해설지 봄.... 
// Good... !!

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		int size = input.size();
		for (int i = 0; i < size; ++i) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				// split input string into two parts and resolve them recursively
				vector<int> result1 = diffWaysToCompute(input.substr(0, i));
				vector<int> result2 = diffWaysToCompute(input.substr(i+1));
				for (auto n1 : result1) {
					for (auto n2 : result2) {
						if(cur == '+') result.push_back(n1 + n2);
						else if (cur == '-') result.push_back(n1-n2);
						else result.push_back(n1*n2);
					}
				}
			}
		}

		// if the input string doesn't contain operator
		if(result.empty()) result.push_back(atoi(input.c_str()));
		return result;

	}
};

int main() {
	char c;
	Solution sol;
	//string s = "2-1-1";
	string s = "2*3-4*5";

	vector<int> ans = sol.diffWaystoCompute(s);
	for( auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}



//
// 아래는  dp solution  이라고.... 해설자가 설명하는...
//

#if 0
There are many repeating subquestions in this recursive method, therefore, we could use dynamic programming to avoid this situation by saving the results for subquestions.Here is the DP solution.

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dpMap;
		return computeWithDP(input, dpMap);
	}

	vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
		vector<int> result;
		int size = input.size();
		for (int i = 0; i < size; i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				// Split input string into two parts and solve them recursively
				vector<int> result1, result2;
				string substr = input.substr(0, i);
				// check if dpMap has the result for substr
				if (dpMap.find(substr) != dpMap.end())
					result1 = dpMap[substr];
				else
					result1 = computeWithDP(substr, dpMap);

				substr = input.substr(i + 1);
				if (dpMap.find(substr) != dpMap.end())
					result2 = dpMap[substr];
				else
					result2 = computeWithDP(substr, dpMap);

				for (auto n1 : result1) {
					for (auto n2 : result2) {
						if (cur == '+')
							result.push_back(n1 + n2);
						else if (cur == '-')
							result.push_back(n1 - n2);
						else
							result.push_back(n1 * n2);
					}
				}
			}
		}
		// if the input string contains only number
		if (result.empty())
			result.push_back(atoi(input.c_str()));
		// save to dpMap
		dpMap[input] = result;
		return result;
	}
};
#endif 