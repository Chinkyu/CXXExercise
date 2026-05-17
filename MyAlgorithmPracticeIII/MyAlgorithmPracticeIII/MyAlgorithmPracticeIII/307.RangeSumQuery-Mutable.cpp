//  see answer

// About binary bit tree 
// https://velog.io/@kimgwon/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%94%EC%9D%B4%EB%84%88%EB%A6%AC-%EC%9D%B8%EB%8D%B1%EC%8A%A4-%ED%8A%B8%EB%A6%ACBinary-Index-Tree-%ED%8E%9C%EC%9C%85-%ED%8A%B8%EB%A6%AC


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
#include <bit>

using namespace std;

// use binary bit tree 
class BIT { // One-based indexing
    vector<int> bit;
public:
    BIT(int size = 0) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};
class NumArray {
    BIT bit;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i)
            bit.addValue(i + 1, nums[i]);
    }
    void update(int index, int val) {
        int diff = val - nums[index]; // get diff amount of `val` compared to current value
        bit.addValue(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing
        nums[index] = val; // update latest value of `nums[index]`
    }
    int sumRange(int left, int right) {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};



//:: ckkang : timeout : say segment tree to solve this 
class _NumArray {
public:
    vector<int> n;
    vector<int> ac;
    int l = 0;
    NumArray(vector<int>& nums) {
        l = nums.size();
        n = nums;

        ac.push_back(n[0]);
        for (int i = 1; i < l; ++i) {
            ac.push_back(ac[i - 1] + n[i]);
        }
    }

    void update(int index, int val) {
        n[index] = val;

        for (int i = index; i < l; ++i) {
            int pre = (i == 0) ? 0 : ac[i - 1];
            ac[i] = pre + n[i];
        }
    }

    int sumRange(int left, int right) {
        int pre = (left == 0) ? 0: ac[left - 1];
        return ac[right] - pre;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    char c;

    vector<int> n = { 1, 3, 5 };

    NumArray sol(n);
    cout << sol.sumRange(0, 2) << " ";
    sol.update(1, 2);
    cout << sol.sumRange(0, 2);

    cin >> c;
}

