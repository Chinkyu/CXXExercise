#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

struct Node {
	bool isExist = false;
	unordered_map<char, struct Node *> map;
};


class WordDictionary {
public:
	struct Node *root;
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		struct Node *p = root;

		for (auto it : word) {
			if (p->map.find(it) != p->map.end()) {
				p = p->map[it];
			}
			else {
				p->map[it] = new Node();
				p = p->map[it];
			}
		}
		p->isExist = true;
	}

	bool sub_search(struct Node *sNode, string word) {
		struct Node *p = sNode;

		//for (auto it : word) {
		for (int i = 0; i < word.size(); ++i) {
			if (word[i] == '.') {
				// if last char is .
				if (i == word.size() - 1) {
					for (auto jt : p->map) {
						if (jt.second->isExist == true) return true;
					}
					return false;
				}

				for (auto jt : p->map) {
					if (sub_search(jt.second, word.substr(i + 1)) == true) return true;
				}
				return false;
			}
			else {
				if (p->map.find(word[i]) == p->map.end()) {
					return false;
				}
				p = p->map[word[i]];
			}
		}
		if (p->isExist == true) {
			return true;
		}
		else {
			return false;
		}
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		struct Node *p = root;

		return sub_search(root, word);
#if 0
		//for (auto it : word) {
		for(int i = 0; i < word.size(); ++i) {
			if (word[i] == '.') {
				for (auto jt : p->map) {
					if (sub_search(jt.second, word.substr(i+1)) == true) return true;
				}
				return false;
			}
			else {
				if (p->map.find(word[i]) == p->map.end()) {
					return false;
				}
				p = p->map[word[i]];
			}
		}
		if (p->isExist == true) {
			return true;
		}
		else {
			return false;
		}
#endif
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
	WordDictionary * obj = new WordDictionary();
	char c;

	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	
//	cout << obj->search("pad");
//	cout << obj->search("bad");
//	cout << obj->search(".ad");
	cout << obj->search("..");
//	cout << obj->search("..");

	cin >> c;
}