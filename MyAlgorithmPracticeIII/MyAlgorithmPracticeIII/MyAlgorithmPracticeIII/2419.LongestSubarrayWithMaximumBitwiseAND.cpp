// Ok : 생각보다 간단한 문제였음 
//  and 연산을 할 필요도 없음...   MAX 값의 최대 연속 개수가 답임... 
// and 를 하면 할 수록 값이 작아지니... 이렇게 계산 가능함.. 
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

// time out 
class _Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = nums.size();

        int mVal = 0;
        int mLen = 0;
        for (int i = 0; i < l; ++i) {
            int v = nums[i]; 

            if (v > mVal) {
                mVal = v;
                mLen = 1;
            } else if (v == mVal) {
                mLen = max(mLen, 1);
            }

            for (int j = i + 1; j < l; ++j) {
                v &= nums[j];

                if (v > mVal) {
                    mVal = v;
                    mLen = j - i + 1;
                } else if (v == mVal) {
                    mLen = max(mLen, j - i + 1);
                }
            }
        }

        return mLen;
    }
};

// timeout 
class __Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = nums.size();


        // find max idx
        int mVal = 0;
        vector<int> ml;
        for (int i = 0; i < l; ++i) {

            if (nums[i] > mVal) {
                mVal = nums[i];
                ml.clear();
                ml.push_back(i);
            }
            else if(mVal == nums[i]) {
                ml.push_back(i);
            }

        }

        mVal = 0;
        int mLen = 0;
        for (auto i: ml) {
            int v = nums[i];

            if (v > mVal) {
                mVal = v;
                mLen = 1;
            }
            else if (v == mVal) {
                mLen = max(mLen, 1);
            }

            for (int j = i + 1; j < l; ++j) {
                v &= nums[j];

                if (v > mVal) {
                    mVal = v;
                    mLen = j - i + 1;
                }
                else if (v == mVal) {
                    mLen = max(mLen, j - i + 1);
                }
            }
        }

        return mLen;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = nums.size();


        // find max idx
        int mVal = 0;
        vector<int> ml;
        for (int i = 0; i < l; ++i) {

            if (nums[i] > mVal) {
                mVal = nums[i];
                ml.clear();
                ml.push_back(i);
            }
            else if (mVal == nums[i]) {
                ml.push_back(i);
            }

        }

        // find continous longest 
        int length = 1;
        int mLength = 1;
        for (int i = 1; i < ml.size(); ++i) {
            if (ml[i - 1] + 1 == ml[i]) {
                length++;
                mLength = max(mLength, length);
            }
            else {
                length = 1;
            }
        }

        return mLength;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> nums = { 323376,323376,323376,323376,323376,323376,323376,75940,75940 };
    // { 1, 2, 3, 3, 2, 2 };

    cout << sol.longestSubarray(nums);

    cin >> c;
}
