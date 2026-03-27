// ok : folow logic
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = plants.size();

        int Ar = capacityA, Br = capacityB;
        int ans = 0;
        for (int i = 0, j = l - 1; i < l / 2; ++i, --j) {

            // Alice
            if (Ar - plants[i] < 0) {
                ans++;
                Ar = capacityA;
            }
            Ar -= plants[i];

            // Bob
            if (Br - plants[j] < 0) {
                ans++;
                Br = capacityB;
            }
            Br -= plants[j];

        }

        if (l % 2 != 0) {
            if (Ar >= Br) {
                // Alice
                if (Ar - plants[l/2] < 0) {
                    ans++;
                    Ar = capacityA;
                }
                Ar -= plants[l / 2];
            }
            else {  // Ar < Br
                // Bob
                if (Br - plants[l/2] < 0) {
                    ans++;
                    Br = capacityB;
                }
                Br -= plants[l / 2];
            }
        }
        
        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> plants = { 2, 2, 3, 3 };

    cout << sol.minimumRefill(plants, 5, 3);

    cin >> c;
}
