#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int hammingdistance(int a, int b) {
		int count = 0;

		for (int i = 0; i < sizeof(a)*8; i++) {
			if ((a & 0x01) != (b & 0x01)) count++;
			a = a >> 1;
			b = b >> 1;
		}
		return count;
	}

	int hammingdistance2(int a, int b) {
		int count = 0;
		int c = a ^ b;

		c = (c & 0x55555555) + ((c >> 1) & 0x55555555);
		c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
		c = (c & 0x0f0f0f0f) + ((c >> 4) & 0x0f0f0f0f);
		c = (c & 0x00ff00ff) + ((c >> 8) & 0x00ff00ff);
		c = (c & 0x0000ffff) + ((c >> 16) & 0x0000ffff);

		return c;
	}

	int totalHammingDistance(vector<int>& nums) {
		int total_distance = 0;
		int v_size = nums.size();
		// need to iterate all combination 
		for (int i = 0; i < v_size; i++) {
			for (int j = i+1; j < v_size; j++) {
				total_distance += hammingdistance2( nums[i], nums[j]);
//				cout << i << " " << j << endl;
			}
		}
		return total_distance;
	}
};



int main() {
	Solution s;
	vector<int> n = { 1337, 7331 };

//	cout << s.hammingdistance(1, 2);

	cout << s.totalHammingDistance(n);
	getchar();


}