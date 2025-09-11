// refer answer : �׳� �տ��� �ϸ� ��... 
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
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;


//�̰Ÿ� �տ��� ���� �ϸ� �ȴٴµ�.. ��¥... �ű��ѵ�... �ȵɰ� ������....... ����ϳ�...
// ��¥�� �ߺ��� �ȵǴϱ�. �Ѱ��� �ۿ� ���°ǰ�?????
class Solution {
public:
    int maxSubstrings(string word) {
        int l = word.size();
        unordered_map<char, int> m;

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (m.find(word[i]) != m.end() && i - m[word[i]] >= 3) {  // if exist
                ans++;
                m.clear();
            }
            else {
                if (m.find(word[i]) == m.end()) m[word[i]] = i;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string word = "aaaeaaa";

    cout << sol.maxSubstrings(word);

    cin >> c;
}