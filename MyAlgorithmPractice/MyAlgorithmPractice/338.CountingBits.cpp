//
// �� ���� 1 �� ������ '���� �� (����-1) ��  and' ==  ���� ������ 1���������� 1�� ��ø�Ǵ� ������ 1�� ���Ѱ��̴�.. 
// => �̰� ��¥�� �´ٴ°���...... ��... ����ϱ�.. !


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