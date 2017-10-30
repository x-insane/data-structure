#ifndef __LEFT_CHILD_RIGHT_SIBLING_H__
#define __LEFT_CHILD_RIGHT_SIBLING_H__

#include "tree.h"
#include <iostream>
using namespace std;

template<typename T>
class LCRSTNode : public GTNodeADT<T> {
	T _d;
	LCRSTNode<T>* _left; // child
	LCRSTNode<T>* _right; // sibling
	LCRSTNode<T>* _parent; // parent
public:
	LCRSTNode(const T& data) {
		_d = data;
		_left = _right = _parent = 0;
	}
	~LCRSTNode() {
		if (!_left)
			return;
		LCRSTNode<T>* lp = _left, *p = _left->_right;
		while (p) {
			delete lp;
			lp = p;
			p = p->_right;
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
		return !_left;
	}
	virtual GTNodeADT<T>* parent() {
		return _parent;
	}
	virtual GTNodeADT<T>* firstChild() {
		return _left;
	}
	virtual GTNodeADT<T>* next() {
		return _right;
	}
	virtual void insertChild(GTNodeADT<T>* t) {
		LCRSTNode<T>* p = (LCRSTNode<T>*)t;
		p->_right = _left;
		p->_parent = this;
		_left = p;
	}
	virtual void insertChild(const T& t) {
		insertChild(new LCRSTNode<T>(t));
	}
	virtual void insertSibling(GTNodeADT<T>* t) {
		LCRSTNode<T>* p = (LCRSTNode<T>*)t;
		p->_right = _right;
		p->_parent = _parent;
		_right = p;
	}
	virtual void insertSibling(const T& t) {
		insertSibling(new LCRSTNode<T>(t));
	}
	virtual void removeFirstChild() {
		if (!_left)
			return;
		LCRSTNode<T>* p = _left;
		_left = p->_right;
		delete p;
	}
	virtual void removeNextSibling() {
		if (!_right)
			return;
		LCRSTNode<T>* p = _right;
		_right = p->_right;
		delete p;
	}
	virtual void print() {
		cout << "Value: " << _d << endl;
		cout << "Children: ";
		LCRSTNode<T>* p = _left;
		while (p) {
			cout << p->_d << " ";
			p = p->_right;
		}
		cout << endl;
	}
};

#endif