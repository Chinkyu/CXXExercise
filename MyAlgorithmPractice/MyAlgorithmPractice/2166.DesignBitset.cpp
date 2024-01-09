// easy : 
//  timeout이 나서...  cunt, isFlip을 변수로 둬서 이것 베이스로  루프 줄임
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

class Bitset {
public:
	vector<int> b;
	int cnt = 0;
	bool isFlip = false;
	Bitset(int size) {
		b = vector<int>(size, 0);
		cnt = 0;
		isFlip = false;
	}

	void fix(int idx) {
		if (isFlip == false) {
			if (b[idx] != 1) cnt++;
			b[idx] = 1;
		}
		else {
			if (b[idx] != 0) cnt++;
			b[idx] = 0;
		}
	}

	void unfix(int idx) {
		if (isFlip == false) {
			if (b[idx] == 1) cnt--;
			b[idx] = 0;
		}
		else {
			if (b[idx] == 0) cnt--;
			b[idx] = 1;
		}
	}

	void flip() {
		isFlip = !isFlip;

		cnt = b.size() - cnt;
	}

	bool all() {
		if (cnt == b.size()) return true;
		return false;
	}

	bool one() {
		if (cnt > 0) return true;
		return false;
	}

	int count() {
		return cnt;
	}

	string toString() {
		string s;

		if (isFlip == false) {
			for (auto &it : b) {
				if (it == 1) {
					s.push_back('1');
				}
				else {
					s.push_back('0');
				}
			}
		}
		else {
			for (auto &it : b) {
				if (it == 1) {
					s.push_back('0');
				}
				else {
					s.push_back('1');
				}
			}
		}
		return s;
	}
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main() {
	char c;

	Solution sol;
	string s = "4670656272980699016272046537556464170805310033092327193745299124190496631931491905865185067165726284987769453147379965075273545494808313678377701436349578856855744431351823374989413435240824008427109477752047116719022941318699938677496499091334123281206797403447134936183242102499471746488771906594013990490278742967175655125674680715451680876038597703482477109324808613171274846773782639821465840449972787558867533963605766270289517187026217459615865780913431611724005045562386922219693792374740748217594647436713695944064090974395339421047095214562328588424745171236851604817549651370985931746120047113826758692617964053773515850643171390053293183933529042284210205395024026811775891783908470076617711592124998569847896118367365766156545271111615280988516560494519832731585149368998094024455022961201836675254599102290147679764381561497840369003432445107622683885160607159696641605297516136968164535218188355231243292127799799552717744905814770054119986798079359782071518203778892554665905151864492";
	//string s = "12321"; // "1212";

	cout << sol.equalDigitFrequency(s);

	cin >> c;
}