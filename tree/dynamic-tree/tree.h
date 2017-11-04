#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
using namespace std;

template<typename T>
class GTNodeADT {
public:
	virtual T value() = 0;
	virtual void setVaule(const T&) = 0;
	virtual bool isLeaf() = 0;
	virtual GTNodeADT<T>* parent() = 0;
	virtual GTNodeADT<T>* firstChild() = 0;
	virtual GTNodeADT<T>* next() = 0;
	virtual void insertChild(GTNodeADT<T>*) = 0; // insert first child
	virtual void insertChild(const T&) = 0;
	virtual void insertSibling(GTNodeADT<T>*) = 0; // insert next sibling
	virtual void insertSibling(const T&) = 0;
	virtual void removeFirstChild() = 0; // remove first child
	virtual void removeNextSibling() = 0; // remove next sibling
	virtual void print() {
		cout << "Value: " << value() << endl;
		cout << "Children: ";
		GTNodeADT<T>* p = firstChild();
		while (p) {
			cout << p->value() << " ";
			p = p->next();
		}
		cout << endl << "Right-Siblings:";
		p = next();
		while (p) {
			cout << p->value() << " ";
			p = p->next();
		}
		cout << endl;
	}
};

template<typename T>
class GTreeADT : public GTNodeADT<T> {
public:
	virtual GTNodeADT<T>* root() = 0;
	virtual void clear() = 0;
	virtual void newRoot(const T& t) = 0;
	virtual bool moveFirstChild() = 0;
	virtual bool moveNext() = 0;
	virtual bool moveParent() = 0;
	virtual void moveRoot() = 0;
};

template<typename T>
class GTree : public GTreeADT<T> {
protected:
	GTNodeADT<T>* _root;
	GTNodeADT<T>* _now;
public:
	// GTree() {
	// 	_now = _root = 0;
	// }
	// GTree(GTNodeADT<T>* root) {
	// 	_now = _root = root;
	// }
	virtual void clear() {
		_now = _root;
		while (_now) {
			GTNodeADT<T>* p = _now->next();
			delete _now;
			_now = p;
		}
		_now = _root = 0;
	}
	// virtual void newRoot(GTNodeADT<T>* root) {
	// 	clear();
	// 	_now = _root = root;
	// }
	virtual GTNodeADT<T>* root() {
		return _root;
	}
	virtual T value() {
		_now->value();
	}
	virtual void setVaule(const T& t) {
		_now->setVaule(t);
	}
	virtual bool isLeaf() {
		_now->isLeaf();
	}
	virtual GTNodeADT<T>* parent() {
		_now->parent();
	}
	virtual GTNodeADT<T>* firstChild() {
		_now->firstChild();
	}
	virtual GTNodeADT<T>* next() {
		_now->next();
	}
	virtual void insertChild(GTNodeADT<T>* t) {
		_now->insertChild(t);
	}
	virtual void insertChild(const T& t) {
		_now->insertChild(t);
	}
	virtual void insertSibling(GTNodeADT<T>* t) {
		_now->insertSibling(t);
	}
	virtual void insertSibling(const T& t) {
		_now->insertSibling(t);
	}
	virtual void removeFirstChild() {
		_now->removeFirstChild();
	}
	virtual void removeNextSibling() {
		_now->removeNextSibling();
	}
	virtual void print() {
		_now->print();
	}
	virtual bool moveFirstChild() {
		GTNodeADT<T>* now = firstChild();
		if (!now)
			return false;
		_now = now;
		return true;
	}
	virtual bool moveNext() {
		GTNodeADT<T>* now = next();
		if (!now)
			return false;
		_now = now;
		return true;
	}
	virtual bool moveParent() {
		GTNodeADT<T>* now = parent();
		if (!now)
			return false;
		_now = now;
		return true;
	}
	virtual void moveRoot() {
		_now = _root;
	}
};


#endif