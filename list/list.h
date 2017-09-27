#ifndef __LIST_D2G3HF8__
#define __LIST_D2G3HF8__

#include <iostream>
using namespace std;

union POSITION {
	long index;
	void* pointer;
};

template <typename T>
class List {
public:
	virtual long length() = 0;
	virtual void append(const T&) = 0;
	virtual List<T>& reverse() = 0;
	virtual bool insert(const POSITION&, const T&) = 0;
	virtual bool remove(const POSITION&) = 0;
	virtual long remove(const T&) = 0;
	virtual void clear() = 0;
	virtual T& operator[](const POSITION&) = 0;
	virtual const T& get(const POSITION& pos) { return operator[](pos); }
	virtual POSITION head() = 0;
	virtual POSITION next(const POSITION&) = 0;
	virtual bool valid_pos(const POSITION&) = 0;
	virtual POSITION find(const T&) = 0;
	virtual POSITION find(const T&, const POSITION&) = 0;
};

template <typename T>
class AList : public List<T> {
	
	static const int _initialSize = 10;
	static const int _stepSize = 10;
	long _size;   // 当前可用空间
	long _length; // 当前已使用空间
	T* data;
	
	void allocate();
	
public:
	static inline void swap(T&, T&);
	
public:
	AList();
	~AList(); 
	long length() { return _length; }
	void append(const T&);
	List<T>& reverse();
	bool insert(const POSITION&, const T&);
	bool remove(const POSITION&);
	long remove(const T&);
	void clear();
	T& operator[](const POSITION&);
	POSITION head() { POSITION pos; pos.index=0; return pos; }
	POSITION next(const POSITION&);
	bool valid_pos(const POSITION& pos) { return (pos.index >= 0 && pos.index < _length); }
	POSITION find(const T& t) { POSITION pos; pos.index=0; find(t, pos); }
	POSITION find(const T&, const POSITION&);
};

template <typename T>
class LList : public List<T> {
	
	struct Node {
		T d;
		Node* left;
		Node* right;
	};
	
	long _length;
	Node* _head;
	Node* _tail;
	
public:
	LList();
	~LList();
	long length() { return _length; }
	void append(const T&);
	List<T>& reverse();
	bool insert(const POSITION&, const T&);
	bool remove(const POSITION&);
	long remove(const T&);
	void clear();
	T& operator[](const POSITION&);
	POSITION head() { POSITION pos; pos.pointer=_head; return pos; }
	POSITION next(const POSITION&);
	bool valid_pos(const POSITION& pos) { return pos.pointer; }
	POSITION find(const T& t) { POSITION pos; pos.pointer=_head; find(t, pos); }
	POSITION find(const T&, const POSITION&);
};

#include "AList.h"
#include "LList.h"

#endif
