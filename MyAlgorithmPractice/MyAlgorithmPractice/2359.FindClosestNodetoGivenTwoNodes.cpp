// 문제 이상함
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
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		set<int> n1set, n2set;
		int ans = -1;

		if (node1 == node2) return node1;

		n1set.insert(node1);
		n2set.insert(node2);

		int p1 = node1, p2 = node2;
		while ((edges[p1] != -1 && n1set.find(edges[p1]) == n1set.end())
			     || (edges[p2] != -1 && n2set.find(edges[p2]) == n2set.end())) {
			if (edges[p1] != -1 && n1set.find(edges[p1]) == n1set.end()) {  // there is arror and not existing loop
				if (n2set.find(edges[p1]) != n2set.end()) {  // if exist in n2set
					return edges[p1];
				}
				else {
					n1set.insert(edges[p1]);
					p1 = edges[p1];
				}
			}
			if (edges[p2] != -1 && n2set.find(edges[p2]) == n2set.end()) {  // there is arror and not existing loop
				if (n1set.find(edges[p2]) != n1set.end()) {  // if exist in n1set
					return edges[p2];
				}
				else {
					n2set.insert(edges[p2]);
					p2 = edges[p2];
				}
			}
		}
		return -1;
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
	cout << sol.closestMeetingNode(edges, 5, 6 );

	cin >> c;

}