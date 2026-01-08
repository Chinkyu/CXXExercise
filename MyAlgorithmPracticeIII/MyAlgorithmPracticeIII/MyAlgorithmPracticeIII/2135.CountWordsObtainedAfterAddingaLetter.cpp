// ok : using accumulation array 
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



int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 4},{2, 3} };
    //vector<vector<int>> grid = { {1, 3},{2, 4} };
    vector<vector<int>> grid = { {1, 1, 1} };

    cout << sol.canPartitionGrid(grid);

    cin >> c;
}
