#ifndef __TREE_H__
#define __TREE_H__

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
	virtual void print() = 0;
};

#endif