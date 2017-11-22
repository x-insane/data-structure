#include <iostream>
#include <cstdio>
using namespace std;

template<typename T>
class BinNode {
	BinNode* left;
	BinNode* right;
	T data;
public:
	BinNode(const T& t) {
		data = t;
		left = right = 0;
	}
	~BinNode() {
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
	BinNode* insert(const T& t) {
		if (t < data)
			left = left ? left->insert(t) : (new BinNode(t));
		else
			right = right ? right->insert(t) : (new BinNode(t));
		return this;
	}
	int height() {
		int lh = left ? left->height() : 0;
		int rh = right ? right->height() : 0;
		return lh > rh ? lh + 1 : rh + 1;
	}
};

int main() {
	BinNode<int>* head = 0;
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		head = new BinNode<int>(tmp);
		while (scanf(",%d", &tmp))
			head->insert(tmp);
		cout << head->height() << endl;
		delete head;
		head = 0;
	}
	return 0;
}
