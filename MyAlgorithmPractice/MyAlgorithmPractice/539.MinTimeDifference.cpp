#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getDistance(string s, string e) {
		istringstream sTime(s), eTime(e);
		string str;
		int sMin, eMin;

		getline(sTime, str, ':');
		sMin = stoi(str) * 60;
		getline(sTime, str);
		sMin += stoi(str);

		getline(eTime, str, ':');
		eMin = stoi(str) * 60;
		getline(eTime, str);
		eMin += stoi(str);

		int delta = abs(sMin - eMin);
		if (delta > 720) delta = 1440 - delta;

		return delta;

	}

	int findMinDifference(vector<string>& timePoints) {
		int l = timePoints.size();
		int min = INT_MAX;

		sort(timePoints.begin(), timePoints.end());

		int d = 0;
		for (int i = 0; i < l-1; ++i) {
			d = getDistance(timePoints[i], timePoints[i + 1]);
			if (d < min) min = d;
		}

		d = getDistance(timePoints[l - 1], timePoints[0]);
		if (d < min) min = d;
		return min;
	}
};

int main() {
	char c;
	Solution sol;

	vector<string> t = { "23:59", "00:05", "00:10" };
	cout << sol.findMinDifference(t);

	cin >> c;
}