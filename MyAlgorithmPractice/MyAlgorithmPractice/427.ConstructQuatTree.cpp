#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};


class Solution {
public:

	Node* traverse(vector < vector<int>> &grid, int sx, int sy, int ex, int ey) {
		Node *p, *q;
		if (sx == ex && sy == ey) {
			p = new Node(grid[sx][sy], true);
			return p;
		}


		// check all value is same 
		int initial = grid[sx][sy];
		bool isAllSame = true;
		for (int i = sx; i <= ex; ++i) {
			for (int j = sy; j <= ey; ++j) {
				if (initial != grid[i][j]) {
					isAllSame = false;
					break;
				}
			}
			if (isAllSame == false) break;
		}

		if (isAllSame == true) {
			p = new Node(grid[sx][sy], true);
		}
		else {
			p = new Node(true, false);
			p->topLeft = traverse(grid, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			//p->topRight = traverse(grid, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			//p->bottomLeft = traverse(grid, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			p->bottomLeft = traverse(grid, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			p->topRight = traverse(grid, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			p->bottomRight = traverse(grid, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		return p;
	}


	Node* construct(vector<vector<int>>& grid) {
		int l = grid.size();
		if (l <= 0) return NULL;
		Node *p = traverse(grid, 0, 0, grid.size()-1, grid.size()-1);
		return p;
	}
};

int main() {
	char c;
	Solution sol;
	vector<vector<int>> grid = { {0, 1},{1, 0} };

	Node *root = sol.construct(grid);

	cin >> c;
}