// see answer
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

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
        vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<int> currRowSum(N, 0);
        vector<int> currColSum(M, 0);

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] =
                    min(rowSum[i] - currRowSum[i], colSum[j] - currColSum[j]);

                currRowSum[i] += origMatrix[i][j];
                currColSum[j] += origMatrix[i][j];
            }
        }
        return origMatrix;
    }
};

int main() {
    char c;

    vector<int> encoding = { 3, 8, 0, 9, 2, 5 };

    RLEIterator* obj = new RLEIterator(encoding);
    cout << obj->next(2) << " ";
    cout << obj->next(1) << " ";
    cout << obj->next(1) << " ";
    cout << obj->next(2) << " ";

    cin >> c;
}
