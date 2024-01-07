// tricky : 
//  타임 아웃이 나서 답 참조함..  count array를 계속 만들지 않고 accumulate하게 하면서 시간 절약 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


// timeout 
class _Solution {
public:
	int equalDigitFrequency(string s) {
		int l = s.length();
		
		int ans = 0;
		unordered_map<string, int> okM, nokM;

		for (int i = 1; i <= l; ++i) {
			for (int j = 0; j < l-i+1; ++j) {
				string ts = s.substr(j, i);
				if (okM.find(ts) != okM.end()) continue;
				if (nokM.find(ts) != nokM.end()) continue;

				if (i == 1) {  // if length is 1 put continue;
					okM[ts]++;
					continue;
				}

				// check all are same number
				unordered_map<char, int> cm;
				for (auto &it : ts) {
					cm[it]++;
				}

				int num = cm.begin()->second;
				bool isAllSameIter = true;
				for (auto &it : cm) {
					if (it.second != num) {
						isAllSameIter = false;
						nokM[ts]++;
						break;
					}
				}

				if (isAllSameIter == true) {
					okM[ts]++;
				}
			}
		}

		return okM.size();
	}
};

// timeout 
class __Solution {
public:
	int equalDigitFrequency(string s) {
		int l = s.length();

		unordered_map<string, int> okM, nokM;

		for (int i = 1; i <= l; ++i) {
			for (int j = 0; j < l - i + 1; ++j) {
				string ts = s.substr(j, i);

				okM[ts]++;
			}
		}

		int ans = 0;
		for(auto &it : okM) {

			if (it.first.size() == 1) {  // if length is 1 put continue;
				ans++;
				continue;
			}

			// check all are same number
			unordered_map<char, int> cm;
			string ts = it.first;
			for (auto &jt : ts) {
				cm[jt]++;
			}

			int num = cm.begin()->second;
			bool isAllSameIter = true;
			for (auto &jt : cm) {
				if (jt.second != num) {
					it.second = 0;
					break;
				}
			}

			if (it.second != 0) ans++;
		}

		return ans;
	}
};

class Solution {
public:
	int equalDigitFrequency(string s) {
		int l = s.length();

		set<string> okM, ansM;

		for (int i = 0; i < l; ++i) {

			unordered_map<char, int> cm;
			for (int j = i; j < l; ++j) {
				string ts = s.substr(i, j - i + 1);

				// check all are same number
				cm[s[j]]++;

				int num = cm.begin()->second;
				bool isAllSameIter = true;
				for (auto &jt : cm) {
					if (jt.second != num) {
						//okM.erase(ts);
						isAllSameIter = false;
						break;
					}
				}
				if (isAllSameIter == true) okM.insert(ts);
			}
		}

		return okM.size();
	}
};


int main() {
	char c;

	Solution sol;
	string s = "4670656272980699016272046537556464170805310033092327193745299124190496631931491905865185067165726284987769453147379965075273545494808313678377701436349578856855744431351823374989413435240824008427109477752047116719022941318699938677496499091334123281206797403447134936183242102499471746488771906594013990490278742967175655125674680715451680876038597703482477109324808613171274846773782639821465840449972787558867533963605766270289517187026217459615865780913431611724005045562386922219693792374740748217594647436713695944064090974395339421047095214562328588424745171236851604817549651370985931746120047113826758692617964053773515850643171390053293183933529042284210205395024026811775891783908470076617711592124998569847896118367365766156545271111615280988516560494519832731585149368998094024455022961201836675254599102290147679764381561497840369003432445107622683885160607159696641605297516136968164535218188355231243292127799799552717744905814770054119986798079359782071518203778892554665905151864492";
	//string s = "12321"; // "1212";

	cout << sol.equalDigitFrequency(s);

	cin >> c;
}