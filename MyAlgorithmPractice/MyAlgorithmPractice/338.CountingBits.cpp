//
// 내 수의 1 의 개수는 '내수 와 (내수-1) 의  and' ==  나와 나보다 1작은수와의 1이 중첩되는 수에서 1을 더한것이다.. 
// => 이게 진짜로 맞다는거지...... 참... 대단하군.. !


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i&(i - 1)] + 1;
		return ret;
	}
};

int main() {
	char c;
	for (int i = 1; i < 100; ++i) {
		cout << i << " " << (i & (i - 1)) << endl;
	}

	cin >> c;
}