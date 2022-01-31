
// use plane sweeping... 
// sorting fuction need to design carefully 


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {

public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		vector<pair<int, int>> p;

		for(auto it : intervals) {
			// remove start and end is same 
			//if (it.start == it.end) continue;

			p.push_back(pair<int,int> (it.start, +1));
			p.push_back(pair<int, int>(it.end, -1));
		}

		sort(p.begin(), p.end(), [](pair<int, int> l, pair<int, int> r) {
			if (l.first == r.first) return l.second > r.second; return l.first < r.first;});

		// preprocessing 
		//for (auto it : p) {
		//	cout << it.first << "," << it.second << endl;
		//}

		int layer = 0;
		int preEnd = -1;
		Interval itv;
		for (auto it : p) {
			if (it.second == 1) {
				if (layer == 0) {
					if (preEnd == it.first) { // -,+ at the sameplace
						itv.end = 0;
						res.pop_back();
					} else {                  // normal start
						itv.start = it.first;
					}
					//cout << "start " << itv.start << " " << endl;
				}
				layer++;
			}
			else if (it.second == -1) {
				layer--;
				if (layer == 0) {
					itv.end = it.first;
					//cout << "  " << itv.start << " " << itv.end << endl;
					res.push_back(itv);
					preEnd = itv.end;
				}
			} // it.second == 0  => ignore
		}
		return res;
	}
};


int main() {
	Solution sol;
	char c;
	//vector<Interval> iv = {{1,3},{2, 6},{8, 10},{15, 18}};
	//vector<Interval> iv = { {1,4},{4,5} };
	//vector<Interval> iv = { {1,4}, {0, 4} };
	vector<Interval> iv = { {5, 5}, {1, 3}, {3, 5}, {4, 6}, {1, 1}, {3, 3}, {5, 6}, {3, 3}, {2, 4}, {0, 0} };

	vector<Interval> s = sol.merge(iv);

	for (auto it : s) {
		cout << it.start << "," << it.end << " ";
	}
	cout << endl;

	cin >> c;
}