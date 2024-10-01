// easy : passed in very last ..
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

class ProductOfNumbers {
public:
    vector<int> nums;
    vector<int> products;
    ProductOfNumbers() {
        nums.clear();
        products.clear();
    }

    void add(int num) {

        for (int i = 0; i < products.size(); ++i) products[i] *= num;
        products.push_back(num);
        nums.push_back(num);
    }

    int getProduct(int k) {
        return products[products.size() - k];
    }
};


int main() {
    char c;
    Solution sol;
    //vector<string> arr = { "cha", "r", "act", "ers" };
    vector<string> arr = {
        "abcdefghijklm", "bcdefghijklmn", "cdefghijklmno", "defghijklmnop", "efghijklmnopq", "fghijklmnopqr", "ghijklmnopqrs", "hijklmnopqrst", "ijklmnopqrstu", "jklmnopqrstuv", "klmnopqrstuvw", "lmnopqrstuvwx", "mnopqrstuvwxy", "nopqrstuvwxyz", "opqrstuvwxyza", "pqrstuvwxyzab"
    };
    cout << sol.maxLength(arr);
    cin >> c;
}