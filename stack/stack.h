#ifndef __STACK_DHUSIKH__
#define __STACK_DHUSIKH__

#include <cstring>

template <typename T>
class Stack {
public:
	virtual long length() = 0;
	virtual void push(const T&) = 0;
	virtual const T& top() throw (const char*) = 0;
	virtual T pop() throw (const char*) = 0;
};

template <typename T>
class AStack : public Stack<T> {
		
	static const int _initialSize = 100;
	static const int _stepSize = 100;
	long _size;   // 当前可用空间
	long _length; // 当前已使用空间
	T* data;
	
	void allocate();
	
public:
	AStack();
	~AStack(); 
	virtual long length() { return _length; }
	virtual void push(const T&);
	virtual const T& top() throw (const char*);
	virtual T pop() throw (const char*);
};

template <typename T>
AStack<T>::AStack() {
	data = new T[_initialSize];
	_size = _initialSize;
	_length = 0;
}

template <typename T>
AStack<T>::~AStack() {
	delete[] data;
}

template <typename T>
void AStack<T>::allocate() {
	T* nd = new T[_size + _stepSize];
	for (long i=0;i<_length;++i)
		nd[i] = data[i];
	delete[] data;
	data = nd;
	_size += _stepSize;
}

template <typename T>
void AStack<T>::push(const T& t) {
	if (_size == _length)
		allocate();
	data[_length++] = t;
}

template <typename T>
const T& AStack<T>::top() throw (const char*) {
	if (!_length)
		throw "Empty stack!";
	return data[_length-1];
}

template <typename T>
T AStack<T>::pop() throw (const char*) {
	if (!_length)
		throw "Empty stack!";
	_length --;
	return data[_length];
}


template <typename T>
class LStack : public Stack<T> {
		
	struct Node {
		T d;
		Node* left;
		Node* right;
	};
	
	long _length;
	Node* _head;
	Node* _tail;
	
public:
	LStack();
	~LStack();
	virtual long length() { return _length; }
	virtual void push(const T&);
	virtual const T& top() throw (const char*);
	virtual T pop() throw (const char*);
};

template <typename T>
LStack<T>::LStack() {
	_head = _tail = 0;
	_length = 0;
}

template <typename T>
LStack<T>::~LStack() {
	if (!_length)
		return;
	for (Node* p=_head;p;p=p->right) {
		if (p->left)
			delete p->left;
	}
	delete _tail;
}

template <typename T>
void LStack<T>::push(const T& t) {
	Node* p = new Node;
	p->d = t;
	p->left = p->right = 0;
	if (!_head)
		_head = _tail = p;
	else {
		_tail->right = p;
		p->left = _tail;
		_tail = p;
	}
	_length ++;
}

template <typename T>
const T& LStack<T>::top() throw (const char*) {
	if (!_length)
		throw "Empty stack!";
	return _tail->d;
}

template <typename T>
T LStack<T>::pop() throw (const char*) {
	if (!_length)
		throw "Empty stack!";
	Node* p = _tail;
	T d = p->d;
	_tail = _tail->left;
	delete p; 
	_length --;
	return d;
}

#endif
