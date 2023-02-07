#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {  // brute force? 
		return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
	}
};


-->  이런 문제는 안나온다... !! 
