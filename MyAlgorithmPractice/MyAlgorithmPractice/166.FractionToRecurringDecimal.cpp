#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// MAP 으로  remainder 가 중복 되면 바로 괄호 처리하는 솔루션 
// 잘해결 안됨... 
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res;
		long long aNum = numerator, aDen = denominator;
		long long ans = 0;

		unordered_map<int, int> repeatMap;
		bool aNegative = (numerator < 0) != (denominator < 0);

		aNum = abs(aNum);
		aDen = abs(aDen);

		long long remain = aNum;
		
		ans = remain / aDen;
		remain = remain - (ans *aDen);
		res = to_string(ans);

		if (aNegative && (ans != 0 || remain != 0)) {
			res = string("-") + res;
		}

		if (remain == 0) return res;
		res.push_back('.');
		repeatMap[remain] = res.size();

		remain = remain * 10;

		while (remain != 0) {
			ans = remain / aDen;
			remain = remain - (ans *aDen);
			//res.push_back(ans + '0');

			if (repeatMap[remain] != 0) {
				//res.push_back(ans + '0');
				res.append(to_string(ans));
				res.insert(repeatMap[remain], "(");
				res.append(")");
				break;
			}
			else {
				repeatMap[remain] = res.size()+1;
				//res.push_back(ans + '0');
				res.append(to_string(ans));
			}

			remain = remain * 10;
		}
		return res;
	}
};


class _Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res;
		int remain = numerator;
		int ans = 0;

		ans = remain / denominator;
		remain = remain - (ans *denominator);
		res.push_back(ans + '0');
		remain = remain * 10;

		if (remain == 0) return res;
		res.push_back('.');

		//int ck_remain = remain;
		string ck_remain;
		int sz_de = log10(denominator) + 1;
		int it = 0;
		int stat = 0;
		int match_len = 0;
		while(remain != 0) {
			ans = remain/denominator;
			remain = remain - (ans *denominator);
			res.push_back(ans + '0');
			remain = remain * 10;

			it++;
			int res_size = res.size();
			if (it > sz_de) 
			{
				if (res[res_size - 1] == res[res_size - 1 - sz_de]) {
					stat = 1;
					match_len++;
				}
				else {
					stat = -1;
					match_len = 0;
				}
			}

			if (match_len >= sz_de * 3 && stat == 1) {
				string nres;

				int i;
				for (i = 0; i < res.size() - sz_de * 4; ++i) {
					nres.push_back(res[i]);
				}
				//nres.push_back('.');
				nres.push_back('(');
				for (int j = res.size() - sz_de; j < res.size(); ++j) {
					nres.push_back(res[j]);
				}
				nres.push_back(')');
				return nres;
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	char c;

	int numerator = -2147483645;
	int denominator = 1;

	cout << sol.fractionToDecimal( numerator, denominator);

	cin >> c;
}
