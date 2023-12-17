// 답봤음
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;


//:: ckkang : gold code 
int main_ck() {
	int n; cin >> n;
	string cow;

	cin >> cow;

	vector<int> group;
	bool isLeft = false, isRight = false;

	char preCow = '0';  // 0 : zero,  1 : one
	int memberCount = 0;

	if (cow[0] == '1') isLeft = true;
	if (cow[n - 1] == '1') isRight = true;

	for (int i = 0; i < n; ++i) {
		if (cow[i] == '1') {
			memberCount++;
		}
		else {			// cow[i] == 0
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
		numSource += ceil((double)group[i] / (min_maxDay*2+1));    // spread : min_maxDay*2+1
	}


	cout << numSource;

	char c;
	cin >> c;

	return 0;
}

int main_ckar(int n, string cow) {
	//int n; cin >> n;
	//string cow;

	//cin >> cow;

	vector<int> group;
	bool isLeft = false, isRight = false;

	char preCow = '0';  // 0 : zero,  1 : one
	int memberCount = 0;

	if (cow[0] == '1') isLeft = true;
	if (cow[n - 1] == '1') isRight = true;

	for (int i = 0; i < n; ++i) {
		if (cow[i] == '1') {
			memberCount++;
		}
		else {			// cow[i] == 0
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

	return 0;
}


int main_sn(void) {
	int N; // 1 ~ 3 * 10^5
	cin >> N;
	//	cout << "N: " << N << endl;

	string tmp;
	vector<int> sum;  // number of consecutive 1's.

	int tsum = 0;
	int first = 0;
	int wall_L = 0;
	int wall_R = 0;
	int maxday = 0;
	int min_maxday = 0x0FFFFFFF;
	int total = 0; // total infected cow

	cin >> tmp;
	for (int i = 0; i < N; i++) {

		//		cout << "1: " << tmp[i] - '0' << endl;
		if (i == 0 && tmp[i] == '1') {
			wall_L = 1;
			first = 1;
		}
		if (i == N - 1 && tmp[i] == '1') {
			wall_R = 1;
			first = 1;
		}

		if (tmp[i] == '1') {
			tsum++;
		}

		//		cout << "first: " << i << ", "<< first << endl;

		if ((tmp[i] == '0' && tsum != 0) || i == N - 1) {
			sum.push_back(tsum);
			if (first == 1) {
				maxday = tsum - 1;
				min_maxday = min(maxday, min_maxday);
				first = 0;
			}
			else {
				maxday = (tsum - 1) / 2;
				min_maxday = min(maxday, min_maxday);
				first = 0;
			}

			//			cout << "2: " << tsum << ", " << maxday << ", " << min_maxday << endl;

			tsum = 0;
		}

	}

	//	cout << "size: " << sum.size() << endl;

	for (int i = 0; i < sum.size(); i++) {
		if (min_maxday == 0) {
			total += sum[i];
		}
		else if (sum[i] < min_maxday * 2) {
			total += 1;
		}
		else {
			int temp2;
			temp2 = sum[i] - min_maxday * 2;
			if (temp2 <= 2) {
				total += temp2;
			}
			else {
				total += 2 + (temp2 % (2 * min_maxday + 1));
			}
		}

		//		cout << "3: " << first << ", " << i << ", " << sum[i] << ", " << total << endl;
	}

	cout << total;

	return 0;
}

int main_snar(int N, string tmp) {
	//int N; // 1 ~ 3 * 10^5
	//cin >> N;
	//	cout << "N: " << N << endl;

	//string tmp;
	vector<int> sum;  // number of consecutive 1's.

	int tsum = 0;
	int first = 0;
	int wall_L = 0;
	int wall_R = 0;
	int maxday = 0;
	int min_maxday = 0x0FFFFFFF;
	int total = 0; // total infected cow

	//cin >> tmp;
	for (int i = 0; i < N; i++) {

		//		cout << "1: " << tmp[i] - '0' << endl;
		if (i == 0 && tmp[i] == '1') {
			wall_L = 1;
			first = 1;
		}
		if (i == N - 1 && tmp[i] == '1') {
			wall_R = 1;
			first = 1;
		}

		if (tmp[i] == '1') {
			tsum++;
		}

		//		cout << "first: " << i << ", "<< first << endl;

		if ((tmp[i] == '0' && tsum != 0) || i == N - 1) {
			sum.push_back(tsum);
			if (first == 1) {
				maxday = tsum - 1;
				min_maxday = min(maxday, min_maxday);
				first = 0;
			}
			else {
				maxday = (tsum - 1) / 2;
				min_maxday = min(maxday, min_maxday);
				first = 0;
			}

			//			cout << "2: " << tsum << ", " << maxday << ", " << min_maxday << endl;

			tsum = 0;
		}

	}

	//	cout << "size: " << sum.size() << endl;

	for (int i = 0; i < sum.size(); i++) {
		if (min_maxday == 0) {
			total += sum[i];
		}
		else if (sum[i] < min_maxday * 2) {
			total += 1;
		}
		else {
			int temp2;
			temp2 = sum[i] - min_maxday * 2;
			if (temp2 <= 2) {
				total += temp2;
			}
			else {
				total += 2 + (temp2 % (2 * min_maxday + 1));
			}
		}

		//		cout << "3: " << first << ", " << i << ", " << sum[i] << ", " << total << endl;
	}

	cout << total;

	return 0;
}

int main() {
	//main_ck();
	//main_sn();

	string s = "1111011111111111111011";
	int n = s.size();


	main_ckar(n, s);
	cout << endl;
	main_snar(n, s);
	   


	char c;
	cin >> c;
}



/*
// back data

//1
5
11111

//4
6
011101

//5
15
011101111011111


// 14
19
1110111111111101000


// 2
36
111111111111111101111111111111111111

// 7,   엄마  2
11011111111111111011

// 7,  엄마 3
111011111111111111011

// 8,  엄마 4
1111011111111111111011


*/