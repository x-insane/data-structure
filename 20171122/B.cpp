#include <iostream>
#include <cstring>
#include <sstream>
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
	int height() {
		int lh = left ? left->height() : 0;
		int rh = right ? right->height() : 0;
		return lh > rh ? lh + 1 : rh + 1;
	}
	bool balanced() {
		int lh = left ? left->height() : 0;
		int rh = right ? right->height() : 0;
		if (abs(lh-rh) > 1)
			return false;
		if (left && !left->balanced())
			return false;
		if (right && !right->balanced())
			return false;
		return true;
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
		cout << (head->balanced() ? 'B' : 'N') << endl;
		delete head;
		head = 0;
	}
	return 0;
}
