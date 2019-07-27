#include <iostream>
#include <stack>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class BSTIterator {
 public:
	 TreeNode *r, *p;
	 vector<int> v;
	 int idx;

	 void traverse(TreeNode *r) {

		 if (r == NULL) return;

		 if (r->left != NULL) traverse(r->left);
		 v.push_back(r->val);
		 if (r->right != NULL) traverse(r->right);
	 }

	 BSTIterator(TreeNode* root) {
		 r = root;
		 p = r;

		 v.clear();
		 traverse(r);
		 idx = 0;
	 }

	 /** @return the next smallest number */
	 int next() {
		 return v[idx++];
	  }

	 /** @return whether we have a next smallest number */
	 bool hasNext() {
		 return (idx < v.size()) ? true : false;
	 }
 };


class _BSTIterator {
public:
	TreeNode *r, *p;
	stack<TreeNode *> st;
	typedef enum {
		LEFT,
		CENTER,
		RIGHT, 
		END
	} state;

	state stat;
    _BSTIterator(TreeNode* root) {
		r = root;
		p = r;
		stat = state::LEFT;
    }

    /** @return the next smallest number */
    int next() {
		int res;

		if (stat == state::END) {
			p = NULL;
			return NULL;
		}
		
		if (stat == state::LEFT) {
			while (p->left != NULL) {
				st.push(p);
				p = p->left;
			}
			res = p->val;
			
			if (st.size() > 0) {
				p = st.top();
				st.pop();
			}
			else {
//				p = NULL;
			}
			stat = state::CENTER;
			return res;
		}
		else if (stat == state::CENTER) {
			if (p != NULL) {
				res = p->val;
			}
			else {
				return NULL;
			}

			if (p->right != NULL) {
				p = p->right;
				stat = state::LEFT;
			}
			else {
				if (st.size() > 0) {
					p = st.top();
					st.pop();
					stat = state::CENTER;
				}
				else {
					p = NULL;
					stat = state::END;
				}
			}

			return res;
		}
		p = NULL;
		return NULL;
	}

    /** @return whether we have a next smallest number */
    bool hasNext() {
		if(st.size() > 0) {
			return true;
		} else {
			if(p == NULL) return false;
			else return true;
		}
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int __main() {
	char c;

	TreeNode *dummyRoot = new TreeNode(7);
	TreeNode *p;

	dummyRoot->left = new TreeNode(3);
	p = dummyRoot->right = new TreeNode(15);

	p->left = new TreeNode(9);
	p->right = new TreeNode(20);

	BSTIterator* obj = new BSTIterator(dummyRoot);
	
	while (obj->hasNext()) {
		cout << obj->next();
	}
	cin >> c;
	return 0;
}


int main() {
	char c;

	TreeNode *dummyRoot = new TreeNode(2);
	TreeNode *p;

	dummyRoot->right = new TreeNode(1);
///	p = dummyRoot->right = new TreeNode(15);

//	p->left = new TreeNode(9);
//	p->right = new TreeNode(20);

	BSTIterator* obj = new BSTIterator(dummyRoot);

	while (obj->hasNext()) {
		cout << obj->next();
	}
	cin >> c;
	return 0;
}
