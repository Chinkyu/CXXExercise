#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;

	for (int tidx = 0; tidx < t; ++tidx) {
		int n; cin >> n;
		vector<int> init(n, 0), speed(n, 0), ranking(n, 0);
		vector<vector<int>> tr(n, vector<int>(4, 0));

		for (int i = 0; i < n; ++i) cin >> init[i];
		for (int i = 0; i < n; ++i) cin >> speed[i];
		for (int i = 0; i < n; ++i) cin >> ranking[i];

		for (int i = 0; i < n; ++i) {
			tr[i][0] = ranking[i];
			tr[i][1] = init[i];
			tr[i][2] = speed[i];
			tr[i][3] = init[i];  // height
		}

		sort(tr.begin(), tr.end(), [](vector<int> &ltr, vector<int> rtr) {
			return ltr[0] < rtr[0];
		});

		vector<int> gap(n, 0);
		int itr = 0;
		bool isAllPlus = true;
		for (int i = 1; i < n; ++i) {
			gap[i] = tr[i - 1][1] - tr[i][1];
			if (gap[i] <= 0) isAllPlus = false;
		}

		if (isAllPlus == true) {
			cout << 0 << endl;
			continue;
		}

		int ans = 0;
		//vector<int> nStep(n, 0);

		int tillOK = INT_MAX, afterOK = 0, next = 0;
		for (int i = 1; i < n; ++i) {
			int plusStep = 0;
			int cGap = tr[i - 1][3] - tr[i][3];
			int cValocityDiff = tr[i - 1][2] - tr[i][2];

			double nStep = (cValocityDiff > 0) ? abs(cGap / cValocityDiff) : INT_MAX;

			// +  +  no problem 
			if (cGap > 0 && cValocityDiff < 0) {
				// + -   till 
				tillOK = min(tillOK, (int)nStep);
			}
			else if (cGap < 0 && cValocityDiff > 0) {
				// -  +  after 
				afterOK = max(afterOK, (int)ceil(nStep)+1);
			}
			else if (cGap <= 0 && cValocityDiff <= 0) {
				// -  -   -1
				ans = -1;
				break;
			}
		}

		if (tillOK >= afterOK && ans != -1) {
			ans = afterOK;
		}
		else {
			ans = -1;
		}

		cout << ans << endl;

	}

	char c;
	cin >> c;
}

