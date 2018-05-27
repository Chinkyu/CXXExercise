/*
Remove duplicated number in sorted array
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int l_num;
		l_num = nums[0];
		for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ){
			if (l_num == *it) { 
				it = nums.erase(it); 
			}
			else {
				l_num = *it;
				it++;
			}
		}
		return nums.size();
	}
};


int main() {
	int i;
	Solution s;

	vector<int> n = { 0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7 };

	for (vector<int>::iterator it = n.begin(); it != n.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;

	vector<int>::iterator it = n.begin();

//	n.erase(it + 3);

#if 0
	i = 0;
	for (int in : n) {
		cout << " " << &in << " " << in;
		cout << " " << &n[i] << " " << n[i] << endl;
		i++;
	}
#endif 

	s.removeDuplicates(n);
	

	for (auto in : n) {
		cout << in;
	}
	cout << endl;
//		n.insert()

	cin >> i;
}