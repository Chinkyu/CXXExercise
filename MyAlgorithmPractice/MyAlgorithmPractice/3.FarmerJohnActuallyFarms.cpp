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

int main_ck() {
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

		int iter = 0;
		do {
			isAllPlus = true;
			iter++;
			for (int i = 0; i < n; ++i) {
				tr[i][3] += tr[i][2];
				if (i >= 1) {  // check gap 

					if ((tr[i - 1][3] - tr[i][3] < gap[i]) ||
						(tr[i - 1][3] - tr[i][3] == gap[i] && tr[i - 1][3] <= tr[i][3])) {
						//return -1; // no solution
						iter = -1;
						isAllPlus = true;
						break;
					}

					gap[i] = tr[i - 1][3] - tr[i][3];
					if (gap[i] <= 0) isAllPlus = false;  // not equal
				}
			}
		} while (false == isAllPlus);

		cout << iter << endl;

	}
	return 0;
}


int main_ckar(int n, vector<int> &init, vector<int> &speed, vector<int> &ranking) {
	int t = 1; //; cin >> t;

	for (int tidx = 0; tidx < t; ++tidx) {
//		int n; cin >> n;
//		vector<int> init(n, 0), speed(n, 0), ranking(n, 0);
		vector<vector<int>> tr(n, vector<int>(4, 0));

//		for (int i = 0; i < n; ++i) cin >> init[i];
//		for (int i = 0; i < n; ++i) cin >> speed[i];
//		for (int i = 0; i < n; ++i) cin >> ranking[i];

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

		int iter = 0;
		do {
			isAllPlus = true;
			iter++;
			for (int i = 0; i < n; ++i) {
				tr[i][3] += tr[i][2];
				if (i >= 1) {  // check gap 

					if (((tr[i - 1][3] - tr[i][3] < gap[i]) && (gap[i] < 0)) ||
						(tr[i - 1][3] - tr[i][3] == gap[i] && tr[i - 1][3] <= tr[i][3])) {
						//return -1; // no solution
						iter = -1;
						isAllPlus = true;
						break;
					}
/* Fix 1 : 			if ((tr[i - 1][3] - tr[i][3] < gap[i]) ||
						(tr[i - 1][3] - tr[i][3] == gap[i] && tr[i - 1][3] <= tr[i][3])) {
						//return -1; // no solution
						iter = -1;
						isAllPlus = true;
						break;
					}
*/

					gap[i] = tr[i - 1][3] - tr[i][3];
					if (gap[i] <= 0) isAllPlus = false;  // not equal
				}
			}
		} while (false == isAllPlus);

		cout << iter << endl;

	}
	return 0;
}

int main() {
	vector<int> init	= { 160,170,110,120,60,50,40};
	vector<int> speed   = { 20,15,30,10,1,1,1};
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	int n = init.size();


	main_ckar(n, init, speed, ranking);

	char c;
	cin >> c;
}



/*
// background data 
	vector<int> init	= { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> speed	= { 3, 3, 3, 3, 3, 3, 3 };
	vector<int> ranking = { 6, 5, 4, 3, 2, 1, 0 };
	0

		vector<int> init	= { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> speed	= { 3, 3, 3, 3, 3, 3, 3 };
	vector<int> ranking = { 5, 6, 4, 3, 2, 1, 0 };
	-1

		vector<int> init	= { 1, 1, 1, 4, 5, 6, 7 };
	vector<int> speed	= { 20, 18, 17, 16, 15, 14, 13 };
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	4 ->  correct


		vector<int> init	= { 1, 3, 1, 4, 5, 6, 7 };
	vector<int> speed	= { 20, 18, 17, 16, 15, 14, 13 };
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	4 -> correct

		vector<int> init	= { 1, 10, 1, 4, 5, 20, 7 };
	vector<int> speed	= { 20, 18, 17, 16, 15, 14, 13 };
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	16 -> correct

		vector<int> init	= { 90, 100, 80, 70, 50, 40, 40 };
	vector<int> speed	= {  7,  6,   5,  5,  5,  2,  1 };
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	11 -> correct

		vector<int> init	= { 200, 100, 80, 70, 50, 40, 50 };
	vector<int> speed	= {  7,  6,   6,  5,  5,  5,  1 };
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	int n = init.size();
	=> 3

	vector<int> init	= { 210,150,110,120,60,50,40};
	vector<int> speed   = { 50,0,30,10,1,1,1};
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	=>  -1 (Wrong), 1(true)
	-> fix :
	if (((tr[i - 1][3] - tr[i][3] < gap[i]) && (gap[i] < 0)) ||   // gap[i] <0

		vector<int> init	= { 210,170,110,120,60,50,40};
	vector<int> speed   = { 50,5,30,10,1,1,1};
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	-> 1(true)

		vector<int> init	= { 160,170,110,120,60,50,40};
	vector<int> speed   = { 20,15,30,10,1,1,1};
	vector<int> ranking = { 0, 1, 2, 3, 4, 5, 6 };
	-> 3(true)



*/