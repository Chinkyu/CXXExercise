// ´äºÃ½¿  -  bsearch 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	double equalizeBuckets(const std::vector<int>& buckets, const double mid, const double retentionPercentage)
	{
		double netDifference = 0;
		for (const int& bucket : buckets)
		{
			if (bucket > mid)
			{
				double diff = bucket - mid;
				netDifference += (retentionPercentage * diff);
			}
			else if (bucket < mid)
			{
				double diff = mid - bucket;
				netDifference -= diff;
			}
		}

		return netDifference;

	}

	double equalizeWater(vector<int>& buckets, int loss) {

		double leftPtr = 10001;
		double rightPtr = 0;

		for (const int& bucket : buckets)
		{
			rightPtr = std::max(rightPtr, static_cast<double>(bucket));
			leftPtr = std::min(leftPtr, static_cast<double>(bucket));
		}

		const double retentionPercentage = 1 - (loss * .01);

		// while leftPtr < rightPtr within the acceptable level
		// of error precision that the problem statement specifies
		while (rightPtr - leftPtr > 0.00001)
		{
			double mid = leftPtr + (rightPtr - leftPtr) / 2.0;

			double netDiff = equalizeBuckets(buckets, mid, retentionPercentage);

			if (netDiff >= 0.0)
			{
				leftPtr = mid;
			}
			else if (netDiff < 0.0)
			{
				rightPtr = mid;
			}
		}

		return leftPtr;
	}
};;

int main() {
	char c;

	Solution sol;

	cout << sol.minMoves(19, 2);

	cin >> c;
}