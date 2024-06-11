// 港疑擠.....?????太?太?太?太? 
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
#include <set>
#include <regex>
#include <memory>

using namespace std;

class Solution {
    // This is the reference map.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Length of each word in words.
        unsigned int length = words[0].size();

        // Initializing the reference map.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iterate for each offset
        // As many times as the number of characters in each word.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Sliding window size.
            unsigned int size = 0;
            // Sliding window memory.
            std::unordered_map<std::string, unsigned int> seen;

            // Iterate over the string, with the step equals to length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                std::string sub = s.substr(i, length);

                // If the word is absent in the reference map,
                // we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences
                // of the word in seen map.
                ++seen[sub];
                ++size;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds
                    // the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window,
                    // shrinking it from the left.
                    --seen[first];
                    --size;
                }

                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};
// 醞犒????? 
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> m;
		int l = words.size();
		int ws = words[0].size();
		int sl = s.size();

		for (int i = 0; i < l; ++i) {
			m[words[i]] = i;
		}
		
		vector<int> v;
		for (int i = 0; i < sl / ws; ++i) {
			string ss = s.substr(i * ws, ws);
			if (m.find(ss) != m.end()) {
				v.push_back(m[ss]);
			}
			else {
				v.push_back(-1);
			}
		}

		vector<int> ans;
		vector<int> vc(l, 0);
		int oc = 0;  // one_count

		for (int i= 0; i < l; ++i) {
			int pre = vc[v[i]];
			vc[v[i]]++;
			if (pre == 1 && vc[v[i]] != 1) oc--;
			if (pre != 1 && vc[v[i]] == 1) oc++;
		}

		if (oc == l) ans.push_back(0);


		for (int i = l; i < v.size(); ++i) {
			

			// remove first
			if (v[i - l] != -1) {
				int pre = vc[v[i - l]];
				vc[v[i - l]]--;
				if (pre == 1 && vc[v[i - l]] != 1) oc--;
				if (pre != 1 && vc[v[i - l]] == 1) oc++;
			}
			// add last
			if (v[i] != -1) {
				int pre = vc[v[i]];
				vc[v[i]]++;
				if (pre == 1 && vc[v[i]] != 1) oc--;
				if (pre != 1 && vc[v[i]] == 1) oc++;
			}

			if (oc == l) ans.push_back((i - l + 1)*ws);
		}


		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//string s = "barfoofoobarthefoobarman";
	//vector<string> words = { "bar", "foo", "the" };

	string s = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };

	vector<int> ans = sol.findSubstring(s, words);

	for (auto& it : ans) {
		cout << it << " ";
	}

	cin >> c;
}