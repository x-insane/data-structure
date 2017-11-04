#ifndef __LINK_BASED_DYNAMIC_CHILDREN_TREE_H__
#define __LINK_BASED_DYNAMIC_CHILDREN_TREE_H__

#include "tree.h"
#include <iostream>
using namespace std;

template<typename T>
class LDCTNode : public GTNodeADT<T> {
	T _d;
	LDCTNode* _parent;
	LDCTNode* _next;
	LDCTNode* _child;
public:
	LDCTNode(const T& data) {
		_d = data;
		_child = _next = _parent = 0;
	}
	~LDCTNode() {
		if (!_child)
			return;
		LDCTNode<T>* lp = _child, *p = _child->_next;
		while (p) {
			delete lp;
			lp = p;
			p = p->_next;
		}
		delete lp;
	}
	virtual T value() {
		return _d;
	}
	virtual void setVaule(const T& data) {
		_d = data;
	}
	virtual bool isLeaf() {
		return !_child;
	}
	virtual GTNodeADT<T>* parent() {
		return _parent;
	}
	virtual GTNodeADT<T>* firstChild() {
		return _child;
	}
	virtual GTNodeADT<T>* next() {
		return _next;
	}
	virtual void insertChild(GTNodeADT<T>* t) {
		LDCTNode<T>* p = (LDCTNode<T>*)t;
		p->_next = _child;
		p->_parent = this;
		_child = p;
	}
	virtual void insertChild(const T& t) {
		insertChild(new LDCTNode<T>(t));
	}
	virtual void insertSibling(GTNodeADT<T>* t) {
		LDCTNode<T>* p = (LDCTNode<T>*)t;
		p->_next = _next;
		p->_parent = _parent;
		_next = p;
	}
	virtual void insertSibling(const T& t) {
		insertSibling(new LDCTNode<T>(t));
	}
	virtual void removeFirstChild() {
		if (!_child)
			return;
		LDCTNode<T>* p = _child;
		_child = p->_next;
		delete p;
	}
	virtual void removeNextSibling() {
		if (!_next)
			return;
		LDCTNode<T>* p = _next;
		_next = p->_next;
		delete p;
	}
	// virtual void print() {
	// 	cout << "Value: " << _d << endl;
	// 	cout << "Children: ";
	// 	LDCTNode<T>* p = _child;
	// 	while (p) {
	// 		cout << p->_d << " ";
	// 		p = p->_next;
	// 	}
	// 	cout << endl << "Right-Siblings:";
	// 	p = _next;
	// 	while (p) {
	// 		cout << p->_d << " ";
	// 		p = p->_next;
	// 	}
	// 	cout << endl;
	// }
};

template<typename T>
class LDCTree : public GTree<T> {
public:
	LDCTree() {
		this->_now = this->_root = 0;
	}
	LDCTree(LDCTNode<T>* root) {
		this->_now = this->_root = root;
	}
	virtual void newRoot(const T& t) {
		this->clear();
		this->_now = this->_root = new LDCTNode<T>(t);
	}
};

#endif