// 이해 안감... 
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
	int maximumGroups(vector<int>& grades) {
		int i = 0, res = 0, l = 2;
		while (i < grades.size())
		{
			i += l++;
			res++;
		}
		return res;
	}
};


int main() {
	char c;

	Solution sol;

	//	vector<int> edges = { 2, 2, 3, -1 };
	//	cout << sol.closestMeetingNode(edges, 0, 1);

	//	vector<int> edges = { 1, 2, -1 };
	//	cout << sol.closestMeetingNode(edges, 0, 2);

	//	vector<int> edges = { 5,4,5,4,3,6,-1 };
	//	cout << sol.closestMeetingNode(edges, 0, 1);

	vector<int> edges = { 4,4,8,-1,9,8,4,4,1,1 };
	cout << sol.closestMeetingNode(edges, 5, 6);

	cin >> c;

}