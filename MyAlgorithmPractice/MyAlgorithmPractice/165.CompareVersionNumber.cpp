#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream in1(version1), in2(version2);
		string s;
		
		for(int i = 0; i < 4; ++i ) {
			s = "0";
			getline(in1, s, '.');
			int v1 = stoi(s);
			s = "0";
			getline(in2, s, '.');
			int v2 = stoi(s);

			if(v1 > v2) return 1;
			else if (v1 < v2) return -1;
		}
		return 0;
    }
};

int main() {
	Solution sol;
	char c;
	string v1 = "1", v2 = "1.1";

	cout << sol.compareVersion( v1, v2);

	cin >> c;
}
