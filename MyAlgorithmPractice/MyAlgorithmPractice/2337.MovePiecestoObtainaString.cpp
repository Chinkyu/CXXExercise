// ´äºÃÀ½......  : 
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
	bool canChange(string start, string target) {
		int i = 0, j = 0, n = start.size();

		while (i < n || j < n) {
			while (i < n && start[i] == '_')
				i++;
			while (j < n && target[j] == '_')
				j++;

			if (i == n || j == n)
				break;

			if (start[i] != target[j])
				return false;

			if (start[i] == 'L')
				if (i < j)
					return false;

			if (start[i] == 'R')
				if (i > j)
					return false;

			i++;
			j++;
		}

		return i == n && j == n;
	}
};


// ÀÌ·¸°Ô´Â ÇØ°á ¾ÈµÊ... 
class _Solution {
public:
	bool canChange(string start, string target) {
		string mstart, mtarget;
		string nstart, ntarget;

		for (auto it : start) {
			if (it == 'L') {
				mstart.append("L_");
			}
			else if (it == 'R') {
				mstart.append("R_");
			}
			else {
				mstart.push_back(it);
			}
		}

		for (auto it : target) {
			if (it == 'L') {
				mtarget.append("L_");
			}
			else if (it == 'R') {
				mtarget.append("R_");
			}
			else {
				mtarget.push_back(it);
			}
		}


		// normalize
		for (int i = 0; i < mstart.size(); ++i) {
			if (nstart.size() > 0 && mstart[i] == '_' && nstart[nstart.size() - 1] == '_') {
				continue;
			}
			nstart.push_back(mstart[i]);
		}

		if (nstart[0] == '_' && nstart[1] == 'L') nstart.erase(nstart.begin());
		if (nstart[nstart.size() - 1] == '_' && nstart[nstart.size() - 2] == 'R') nstart.erase(--nstart.end());

		for (int i = 0; i < mtarget.size(); ++i) {
			if (ntarget.size() > 0 && mtarget[i] == '_' && ntarget[ntarget.size() - 1] == '_') {
				continue;
			}
			ntarget.push_back(mtarget[i]);
		}
		if (ntarget[0] == '_' && ntarget[1] == 'L') ntarget.erase(ntarget.begin());
		if (ntarget[ntarget.size() - 1] == '_' && ntarget[ntarget.size() - 2] == 'R') ntarget.erase(--ntarget.end());

		if (nstart == ntarget) {
			return true;
		}
		return false;
	}
};

int main() {
	char c;

	Solution sol;

	string start = "_L__R__R_", target = "L______RR";
	//string start = "_R", target = "R_";

	cout << sol.canChange(start, target);

	cin >> c;

}