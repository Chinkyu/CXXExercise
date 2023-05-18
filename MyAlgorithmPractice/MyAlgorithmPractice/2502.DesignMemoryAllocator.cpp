// 사이즈 아이디로 맵에 두번째 element 가 좀 해깔려 시간 까먹음.. 나머지는  ok

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


class Allocator {
public:
	map<int, pair<int, int>> alloc_mem;   // pair<size, mId>
	int l = 0;
	Allocator(int n) {
		alloc_mem.clear();
		l = n;
		alloc_mem[-1] = make_pair(-1, -1);
		alloc_mem[l] = make_pair(-1, -1);
	}

	int allocate(int size, int mID) {
		for (auto it = alloc_mem.begin(); it != alloc_mem.end(); ++it) {
			// check size 
			if(it->first != l) {  // not end node
				auto nxt = next(it);
				int empty_size = 0;
				int empty_idx = 0;
				
				if (it->first == -1) {
					if (nxt->first == l) {
						empty_size = l;
						empty_idx = 0;
					}
					else {
						empty_size = nxt->first;
						empty_idx = 0;
					}
				}
				else {
					empty_size = nxt->first - it->first - it->second.first;
					empty_idx = it->first + it->second.first;
				}

				if (empty_size >= size) {
					alloc_mem[empty_idx] = make_pair(size, mID);
					return empty_idx;
				}
			}
		}
		return -1;
	}

	int free(int mID) {
		int fnum = 0;
		for (auto it = alloc_mem.begin(), next_it = it; it != alloc_mem.end(); it = next_it) {
			
			next_it++;
			if (it->second.second == mID) {
				fnum += it->second.first;
				alloc_mem.erase(it);
			}
		}
		return fnum;
	}
};

int main() {
	char c;

	Allocator alloc(10);

	alloc.allocate(1, 1);
	alloc.allocate(1, 2);
	alloc.allocate(1, 3);
	alloc.free(2);
	alloc.allocate(3, 4);
	alloc.allocate(1, 1);
	alloc.allocate(1, 1);
	alloc.free(1);
	alloc.allocate(10, 2);
	alloc.free(7);

//	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}