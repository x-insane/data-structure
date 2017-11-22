#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class CharBinNode {
	CharBinNode* left;
	CharBinNode* right;
	CharBinNode* parent;
	char data;
public:
	static char last;
	static int abs(int x) {
		return x > 0 ? x : -x;
	}
public:
	CharBinNode(const char& t) {
		data = t;
		left = right = parent = 0;
		last = t;
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
	CharBinNode* insert(const char& t) {
		if (data >= 'a') {
			if (left)
				return left->insert(t);
			else {
				left = new CharBinNode(t);
				left->parent = this;
				return left;
			}
		}
		return parent->insertRight(t);
	}
	CharBinNode* insertRight(const char& t) {
		if (!right) {
			right = new CharBinNode(t);
			right->parent = this;
			return right;
		}
		else if (right->data <= 'Z')
			return parent->insertRight(t);
		return right->insert(t);
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

char CharBinNode::last = 0;

int main() {
	CharBinNode* head = 0, *p = 0;
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i=0;i<n;i++) {
		getline(cin, s);
		stringstream ss(s);
		char tmp;
		while (ss >> tmp)
			p = head ? p->insert(tmp) : (head = new CharBinNode(tmp));
		cout << (head->balanced() ? 'B' : 'N') << endl;
		delete head;
		head = 0;
	}
	return 0;
}
