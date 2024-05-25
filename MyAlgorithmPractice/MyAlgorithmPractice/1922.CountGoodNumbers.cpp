// ¥‰∫√¿Ω.... 
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
    long long power(long long n, long long t) {
        if (t == 0) {
            return 1;
        }
        if (t % 2 == 0) {
            long long key = power(n, t / 2) % 1000000007;
            return (key % 1000000007) * (key % 1000000007);
        }
        long long key = power(n, t - 1) % 1000000007;
        return (key * n) % 1000000007;
    }
    long long countGoodNumbers(long long n) {
        long long even = 5;
        long long prime = 4;
        if (n % 2 == 0) {
            long long e = n / 2;
            return (power(5, e) % 1000000007) * (power(4, e) % 1000000007) % 1000000007;
        }
        long long e = n / 2;
        return (power(5, e + 1) % 1000000007) * (power(4, e) % 1000000007) % 1000000007;
    }
};

int main() {
	char c;
	Solution sol;

	vector<vector<char>> maze =
	{ {'.', '+', '+', '+', '+'},
	  {'.', '+', '.', '.', '.'},
	  {'.', '+', '.', '+', '.'},
	  {'.', '.', '.', '+', '.'},
	  {'+', '+', '+', '+', '.'} };
	//{ {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'} };

	vector<int> entrance = { 0, 0 };
	cout << sol.nearestExit(maze, entrance);

	cin >> c;
}