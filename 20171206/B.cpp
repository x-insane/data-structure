#include <iostream>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;

class CharBinNode {
	CharBinNode* left;
	CharBinNode* right;
	char data;
	bool full;
public:
	CharBinNode(const char& t) {
		data = t;
		left = right = 0;
		full = false;
	}
	~CharBinNode() {
		clear();
	}
	void clear() {
		if (left) {
			left->clear();
			delete left;
			left = 0;
		}
		if (right) {
			right->clear();
			delete right;
			right = 0;
		}
	}
	bool insert(const char& t) {
		if (!left) {
			left = new CharBinNode(t);
			if (t <= 'Z')
				left->full = true;
		}
		else if (!left->full)
			left->insert(t);
		else if (!right) {
			right = new CharBinNode(t);
			if (t <= 'Z')
				full = right->full = true;
		}
		else if (!right->full)
			full = right->insert(t);
		return full;
	}
	void level_out() {
		queue<CharBinNode*> s;
		s.push(this);
		CharBinNode* now = 0;
		while(s.size()) {
			now = s.front();
			s.pop();
			cout << now->data;
			if (now->left)
				s.push(now->left);
			if (now->right)
				s.push(now->right);
		}
		cout << endl;
	}
};

int main() {
	CharBinNode* head = 0;
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i=0;i<n;i++) {
		getline(cin, s);
		stringstream ss(s);
		char tmp;
		while (ss >> tmp) {
			if (!(tmp>='a'&&tmp<='z') && !(tmp>='A'&&tmp<='Z'))
				continue;
			if (head)
				head->insert(tmp);
			else
				head = new CharBinNode(tmp);
		}
		if (head) {
			head->level_out();
			delete head;
		}
		head = 0;
	}
	return 0;
}
