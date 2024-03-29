//  ¥‰∫√¿Ω : ≈∏¿‘æ∆øÙ
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class StockPrice {
public:
	map<int, int> mp;
	multiset<int> mset;
	//priority_queue<int> maxheap;
	//priority_queue<int,vector<int>,greater<int>> minheap;
	int time = 0; int curr = 0;
	StockPrice() {

	}

	void update(int timestamp, int price) {
		if (timestamp >= time) { curr = price; time = timestamp; }
		if (mp.find(timestamp) == mp.end()) {
			mp.insert({ timestamp,price });
			mset.insert(price);
		}
		else {
			auto it = mset.find(mp[timestamp]);
			mset.erase(it);
			mp[timestamp] = price;
			mset.insert(price);
		}

	}

	int current() {
		return curr;
	}

	int maximum() {
		//return maxheap.top();
		return *(mset.rbegin());
	}

	int minimum() {
		//return minheap.top();
		return *(mset.begin());
	}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

class StockPrice {
public:
	map<int, int> m;
	int min;
	int max;

	StockPrice() {
		m.clear();
		min = -1;
		max = -1;
	}

	void update(int timestamp, int price) {
		m[timestamp] = price;

		if (min == -1) {
			int tmin = INT_MAX;
			int tmax = -1;
			for (auto &it : m) {
				if (tmin >= it.second) {
					tmin = it.second;
					min = it.first;
				}

				if (tmax <= it.second) {
					tmax = it.second;
					max = it.first;
				}
			}
		}


		if (timestamp == min || timestamp == max) {
			min = -1;

			int tmin = INT_MAX;
			int tmax = -1;
			for (auto &it : m) {
				if (tmin >= it.second) {
					tmin = it.second;
					min = it.first;
				}

				if (tmax <= it.second) {
					tmax = it.second;
					max = it.first;
				}
			}

			return;
		}
	}

	int current() {
		return m.rbegin()->second;
	}

	int maximum() {
		if (min == -1) {
			int tmin = INT_MAX;
			int tmax = -1;
			for (auto &it : m) {
				if (tmin >= it.second) {
					tmin = it.second;
					min = it.first;
				}

				if (tmax <= it.second) {
					tmax = it.second;
					max = it.first;
				}
			}
		}

		return m[max];
	}

	int minimum() {
		if (min == -1) {
			int tmin = INT_MAX;
			int tmax = -1;
			for (auto &it : m) {
				if (tmin >= it.second) {
					tmin = it.second;
					min = it.first;
				}

				if (tmax <= it.second) {
					tmax = it.second;
					max = it.first;
				}
			}
		}

		return m[min];
	}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main() {
	char c;
	Solution sol;

	vector<int> nums = { -2,2,4,-1 };

	cout << sol.maximumAlternatingSubarraySum(nums);

	cin >> c;
}