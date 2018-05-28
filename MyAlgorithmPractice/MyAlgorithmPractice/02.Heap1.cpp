#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dump(vector<int> &v) {
	for (auto i : v) {
		cout << " " << i;
	}
	cout << endl;
}

void heap_test() {
	vector<int> v = { 3, 4, 5, 8, 6, 3, 2, 1, 1, 9 };

	make_heap(v.begin(), v.end());  // vector ��  heap���� �����

	dump(v);

	pop_heap(v.begin(), v.end());  // ���� ū�� ���� �� �ڷ� ������

	dump(v);

	v.pop_back();                  // �ǵ� ���� �����..

	dump(v);

	v.push_back(10);               // �ǵڿ� �� ���� �߰� �ϱ�

	dump(v);

	push_heap(v.begin(), v.end()); // �ǵ��� ����  heap�� �߰� �ϱ�. 

	dump(v);
}


int main() {
	heap_test();

	getchar();

}