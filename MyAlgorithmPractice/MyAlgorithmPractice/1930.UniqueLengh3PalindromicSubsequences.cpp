// 답봤음...  앞에서 찾고 뒤에서 찾아서.... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


class Solution {
public:
	//koi letter firse mil gaya to beech ke jitne letter hai unke saath mai bnaunga subsequence     vo bhi  palindromic
	//unique ke liye apan ko chaiye beech mai unique
	int countPalindromicSubsequence(string s) {
		int counter = 0;
		unordered_set<char> set;
		//unique characters ke liye hi left right dhundo, what if do a aagaye start mai, do a aagaye right mai, ho jayegi na duplicacy
		for (char ch : s) set.insert(ch);
		for (char ch : set) {
			int firstIdx = s.find(ch);
			int lastIdx = s.rfind(ch);
			if (lastIdx > firstIdx) {
				//ab isme chaiye unique characters ka count
				unordered_set<char> uniqueInBetween;
				for (int i = firstIdx + 1; i < lastIdx; i++) {
					uniqueInBetween.insert(s[i]);
				}
				counter += uniqueInBetween.size();
			}

		}
		return counter;
	}
};

// timeout 
class _Solution {
public:

	int countPalindromicSubsequence(string s) {
		unordered_set<string> st;
		int l = s.size();

		string cstr = "  ";
		for (int i = 0; i < l - 2; ++i) {
			cstr[0] = s[i];
			for (int j = i + 1; j < l - 1; ++j) {
				cstr[1] = s[j];
				// pron if exist
				if (st.find(cstr) != st.end()) {
					continue;
				}

				for (int k = j + 1; k < l; ++k) {
					if (s[i] == s[k]) {
						st.insert(cstr);
					}
				}
			}

		}
		return st.size();
	}
};

void test_set() {
	set<string> s1;

	string st1 = "  ";
	st1[0] = 'a'; st1[1] = 'b';
	s1.insert("abcd");
	s1.insert("a");
	s1.insert(st1);

	cout << *s1.find("ab") << endl;


}



int main() {
	char c;
	Solution sol;

	string s =  "bgpjrthbpdjvptqjlzkbggicrwcenarknkamaioicmrfmvrehzfqzbwfghouqyspphonljbvnhrikgnrowqnemrvygqvwxysbfmgttvkwxqvgherggdauimzkxfhauhoqbsubxihbyxrxkvvgondrpunmcpuivtutyfcfhkwbnscomghudmjiqxatubxrgkqsxrnglayyxhythwelivquhcumtyikxcegbksoistqelqafhocgstqdpkylwdepihcjkjvoaaopfcmgwbqpdyeoanuyvmffyvgtjlffvseeuazglgpqcmwzkfjlpbobymjprusvanjzrdxbeemimcslgizmzhjlxgvynletmyoxqlebememdxmlzolcsdjfhvtvorfzatexgmcihzdjycialsmqhribqlyzxudwuhutopcggukafkkqyehutxxpjcjflkgpckjeqcnzrqsynqcmcuhzrhglooxnnkmsvjptatmuvbksistlvixvfczgrlakarlkrtshvqrzrucdevseamdgvwocudkdxtlmalghvkicwlkmptzaknsyxwgbaoogqxdqqllesmlnprxwsmwskkyqjmzefrcmeemuymgoz";
		//"aabca";


	//test_set();

	cout << sol.countPalindromicSubsequence(s);

	cin >> c;
}