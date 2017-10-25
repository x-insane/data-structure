#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <cstdlib>
#include "queue.h"

template<typename T>
class BinNode {
	BinNode* left;
	BinNode* right;
	T data;
public:
	typedef void (*OUT_FUNC)(const T&);
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
		if (rand() % 2)
			left = left ? left->insert(t) : (new BinNode(t));
		else
			right = right ? right->insert(t) : (new BinNode(t));
		return this;
	}
	BinNode* level_out(OUT_FUNC func) {
		AQueue<BinNode*> s;
		s.push(this);
		BinNode* now = 0;
		try {
			while(now = s.pop()) {
				func(now->data);
				if (now->left)
					s.push(now->left);
				if (now->right)
					s.push(now->right);
			}
		} catch (const char* s) { ; }
		return this;
	}
	BinNode* preorder_out(OUT_FUNC func) {
		func(data);
		if (left)
			left->preorder_out(func);
		if (right)
			right->preorder_out(func);
		return this;
	}
	BinNode* inorder_out(OUT_FUNC func) {
		if (left)
			left->inorder_out(func);
		func(data);
		if (right)
			right->inorder_out(func);
		return this;
	}
	BinNode* postorder_out(OUT_FUNC func) {
		if (left)
			left->postorder_out(func);
		if (right)
			right->postorder_out(func);
		func(data);
		return this;
	}
	int height() {
		int lh = left ? left->height() : 0;
		int rh = right ? right->height() : 0;
		return lh > rh ? lh + 1 : rh + 1;
	}
	bool is_leaf() {
		if (left || right)
			return false;
		return true;
	}
	int leaf_num() {
		int ln = left ? left->leaf_num() : 0;
		int rn = right ? right->leaf_num() : 0;
		return ln + rn + is_leaf();
	}
};

#endif