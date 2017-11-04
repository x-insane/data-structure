#ifndef __ARRAY_BASED_DYNAMIC_CHILDREN_TREE_H__
#define __ARRAY_BASED_DYNAMIC_CHILDREN_TREE_H__

#include "tree.h"
#include <iostream>
using namespace std;

template<typename T>
class ADCTNode : public GTNodeADT<T> {
	T _d;
	ADCTNode* _parent;
	ADCTNode** _child;
	int _child_num; // 孩子个数
	int _child_size;
	enum {
		INIT_SIZE = 10,
		STEP_SIZE = 10
	};
private:
	void allocate() {
		_child_size += STEP_SIZE;
		ADCTNode** _child_new = new ADCTNode*[_child_size];
		for (int i=0;i<_child_num;++i)
			_child_new[i] = _child[i];
		delete[] _child;
		_child = _child_new;
	}
public:
	ADCTNode(const T& t) {
		_parent = 0;
		_child = new ADCTNode*[INIT_SIZE];
		_child_size = INIT_SIZE;
		_child_num = 0;
		_d = t;
	}
	~ADCTNode() {
		for (int i=0;i<_child_num-1;++i)
			delete _child[i];
		if (_child)
			delete[] _child;
	}
	virtual T value() {
		return _d;
	}
	virtual void setVaule(const T& t) {
		_d = t;
	}
	virtual bool isLeaf() {
		return !_child_num;
	}
	virtual GTNodeADT<T>* parent() {
		return _parent;
	}
	virtual GTNodeADT<T>* firstChild() {
		if (!_child_num)
			return 0;
		return _child[_child_num-1];
	}
	virtual GTNodeADT<T>* next() {
		for (int i=_parent->_child_num-1;i>0;--i) {
			ADCTNode* p = _parent->_child[i];
			if (p == this)
				return _parent->_child[i-1];
		}
		return 0;
	}
	virtual void insertChild(GTNodeADT<T>* t) {
		if (_child_num == _child_size)
			allocate();
		ADCTNode<T>* p = (ADCTNode<T>*)t;
		p->_parent = this;
		_child[_child_num++] = p;
	}
	virtual void insertChild(const T& t) {
		insertChild(new ADCTNode(t));
	}
	virtual void insertSibling(GTNodeADT<T>* t) {
		if (_parent->_child_num == _parent->_child_size)
			_parent->allocate();
		int i = _parent->_child_num - 1, j;
		while (i>=0 && _parent->_child[i--] != this);
		if (_parent->_child[i+1] != this)
			return;
		for (j=_parent->_child_num;j>i+1;--j)
			_parent->_child[j] = _parent->_child[j-1];
		ADCTNode<T>* p = (ADCTNode<T>*)t;
		p->_parent = _parent;
		_parent->_child[j] = p;
		_parent->_child_num++;
	}
	virtual void insertSibling(const T& t) {
		insertSibling(new ADCTNode(t));
	}
	virtual void removeFirstChild() {
		if (!_child_num)
			return;
		delete _child[_child_num-1];
		_child_num --;
		_child[_child_num] = 0;
	}
	virtual void removeNextSibling() {
		int i = _parent->_child_num - 1;
		while (i>=0 && _parent->_child[i--] != this);
		if (_child[i+1] != this || i<0)
			return;
		for (int j=i;j<_parent->_child_num-1;++j)
			_child[j] = _child[j+1];
		delete _parent->_child[--(_parent->_child_num)];
	}
};

template<typename T>
class ADCTree : public GTree<T> {
public:
	ADCTree() {
		this->_now = 0;
		this->_root = 0;
	}
	ADCTree(ADCTNode<T>* root) {
		newRoot(root);
	}
	virtual void newRoot(const T& t) {
		clear();
		this->_root = new ADCTNode<T>(t);
		this->_root->insertChild(t);
		this->_now = this->_root->firstChild();
	}
	virtual void clear() {
		delete this->_root;
		this->_now = 0;
		this->_root = 0;
	}
	virtual GTNodeADT<T>* root() {
		if (!this->_root)
			return 0;
		return this->_root->firstChild();
	}
	virtual void moveRoot() {
		this->_now = this->_root->firstChild();
	}
};

#endif