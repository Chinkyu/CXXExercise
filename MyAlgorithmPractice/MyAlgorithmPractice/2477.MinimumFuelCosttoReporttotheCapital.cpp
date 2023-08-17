// copy answer - Need to check later 
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
#define ll long long int
	pair<ll, ll> solve(vector<vector<int>> &arr, int se, int i, ll &ans, int pr)
	{
		if (arr[i].size() == 0)
		{
			ans++;
			return { 1, 1 };
		}
		pair<ll, ll> temp;
		temp.first = 0;
		temp.second = 0;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] != pr)
			{

				pair<ll, ll> p = solve(arr, se, arr[i][j], ans, i);
				temp.first += p.first;
				temp.second += p.second;
			}
		}

		ll maxi = temp.second * se;
		if (temp.first < maxi)
		{
			while (((temp.second - 1) * se) > temp.first)
			{
				temp.second--;
			}

			temp.first++;
			ans += temp.second;
			return temp;
		}
		temp.second++;
		temp.first++;
		ans += temp.second;
		return temp;
	}
	long long minimumFuelCost(vector<vector<int>> &a, int se)
	{
		int n = a.size();
		vector<vector<int>> arr(n + 1);
		for (int i = 0; i < n; i++)
		{
			arr[a[i][0]].push_back(a[i][1]);
			arr[a[i][1]].push_back(a[i][0]);
		}
		ll ans = 0;
		for (int i = 0; i < arr[0].size(); i++)
		{
			pair<ll, ll> x = solve(arr, se, arr[0][i], ans, 0);
		}
		return ans;
	}
};

// Not working for joint Rriding. 

class Solution {
public:
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		int l = roads.size();
		unordered_map<int, vector<int>> m;
		unordered_map<int, bool> visit;
		vector<int> end_node;
		for (auto it : roads) {
			m[it[0]].push_back(it[1]);
			m[it[1]].push_back(it[0]);
		}

		queue<int> q;
		int depth = 0;
		q.push(0);
		while (!q.empty()) {
			queue<int> tq;
			while (!q.empty()) {
				int n = q.front();
				q.pop();
				visit[n] = true;

				if (m.find(n) != m.end()) {
					bool isWayToGo = false;
					for (auto it : m[n]) {
						if (visit[it] == false) {
							tq.push(it);
							isWayToGo = true;
						}
					}
					if (isWayToGo == false) end_node.push_back(depth);
				}
				else {
					end_node.push_back(depth);
				}
			}
			q = tq;
			depth++;
		}

		bool isAllZero = true;
		long long ans = 0;
		do {
			isAllZero = true;
			for (int i = 0; i < end_node.size(); i++) {
				if (end_node[i] != 0) {
					isAllZero = false;
					if (end_node[i] > seats) {
						ans += end_node[i];
						end_node[i] -= seats;
					}
					else {
						ans += end_node[i];
						end_node[i] = 0;
					}
				}
			}

		} while (isAllZero == false);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> roads = { {0, 1},{0, 2},{0, 3} };
	
	cout << sol.minimumFuelCost(roads, 5);

	cin >> c;
}