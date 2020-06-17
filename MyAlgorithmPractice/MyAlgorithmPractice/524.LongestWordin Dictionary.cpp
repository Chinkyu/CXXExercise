#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	bool isSubsequence(string s, string cs) {
		if (cs.size() > s.size()) return false;

		int sz = s.size();
		int csz = cs.size();
		int i = 0;
		for (int j = 0; j < csz; ++j) {
			do {
				if (cs[j] == s[i]) {
					i++;
					if (j == csz - 1) return true;
					break;
				}
				else {
					i++;
				}
			} while (i < sz);

			if (i >= sz) {
					return false;
			}
		}
		return true;
	}

//	string findLongestWord(string s, vector<string>& d) {
//		string a = "mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq";
//		cout << isSubsequence(a, "ettphsiunoglotjlccurlre");
//		cout << isSubsequence(a, "ntgcykxhdfescxxypyew");
//		return "";
//	}

	string findLongestWord(string s, vector<string>& d) {
		//cout << isSubsequence("abpcplea", "apple");
		string ans = "";
		int max = 0; // INT_MIN;

		for (auto it : d) {
			if (isSubsequence(s, it)) {
				if ((max < it.size()) ||
					((max == it.size() && ans > it))) {
					max = it.size();
					ans = it;
				}
			}
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

//	vector<string> vs = {"ale", "apple", "monkey", "plea"};
//	string s = "abpcplea";
	
//	vector<string> vs = {"aaa", "aa", "a"};
//	string s = "aaa";

	vector<string> vs = { "ba", "ab", "a", "b" };
	string s = "bab";


	string ans = sol.findLongestWord(s, vs);

	cout << ans.c_str();

	cin >> c;
}