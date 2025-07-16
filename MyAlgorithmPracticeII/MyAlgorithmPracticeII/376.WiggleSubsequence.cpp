//  See solution 
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

using namespace std;

/*
* 
The demand of the question is to get INCREASING and DECREASING sequences alternating.
�󸶳� �Դ� ���� �ϴ��� ȸ���� �� ���ϴ� ������... 
 �Ʒ� �ذ��� �ַ�ǵ� ����ϴ�..... !!
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size(), peak = 1, valley = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) peak = valley + 1;
            else if (nums[i] < nums[i - 1]) valley = peak + 1;
        }
        return max(peak, valley);
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> ans = sol.generateMatrix(3);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}