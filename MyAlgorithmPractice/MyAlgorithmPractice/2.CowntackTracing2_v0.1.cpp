#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	string cow;

	cin >> cow;

	vector<int> group;
	bool isLeft = false, isRight = false;

	char preCow = '0';  // 0 : zero,  1 : one
	int memberCount = 0;

	// isLeft, isRight true?? 
	if (cow[0] == '1') isLeft = true;
	if (cow[n - 1] == '1') isRight = true;

	for (int i = 0; i < n; ++i) {
		if (cow[i] == '1') {
			memberCount++;
		}
		else {						// cow[i] == 0
			if (preCow == '1') {
				group.push_back(memberCount);
				memberCount = 0;
			}
		}
		preCow = cow[i];
	}

	if (memberCount > 0) {
		group.push_back(memberCount);
	}

	int min_maxDay = INT_MAX;
	for (int i = 0; i < group.size(); ++i) {
		if (isLeft == true && i == 0) {							// left end
			min_maxDay = min(min_maxDay, group[i] - 1);
		}
		else if (isRight == true && i == group.size() - 1) {	// right end
			min_maxDay = min(min_maxDay, group[i] - 1);
		}
		else {													// middle
			min_maxDay = min(min_maxDay, (group[i] - 1) / 2);
		}
	}

	// find min source
	int numSource = 0;
	for (int i = 0; i < group.size(); ++i) {
		numSource += ceil((double)group[i] / (min_maxDay * 2 + 1));    // spread : min_maxDay*2+1
	}
	
	cout << numSource;

	// pause
	char c;
	cin >> c;

	return 0;
}
