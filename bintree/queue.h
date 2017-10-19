#ifndef __QUEUE_DHYIFYU__
#define __QUEUE_DHYIFYU__

template <typename T>
class Queue {
public:
	virtual long length() = 0;
	virtual void push(const T&) throw (const char*) = 0;
	virtual const T& top() throw (const char*) = 0;
	virtual T pop() throw (const char*) = 0;
};

template <typename T>
class AQueue : public Queue<T> {
	
	static const long _maxLength = 100;

	T data[_maxLength];
	
	long _top;
	long _tail;
	
public:
	AQueue();
	virtual long length() { return (_tail - _top) % _maxLength; }
	virtual void push(const T&) throw (const char*);
	virtual const T& top() throw (const char*);
	virtual T pop() throw (const char*);
};

template <typename T>
AQueue<T>::AQueue() {
	_top = _tail = 0;
}

template <typename T>
void AQueue<T>::push(const T& t) throw (const char*) {
	if ((_tail+1)%_maxLength == _top)
		throw "Array Queue overflow!";
	data[_tail++] = t;
	_tail %= _maxLength;
}

template <typename T>
const T& AQueue<T>::top() throw (const char*) {
	if (_top == _tail)
		throw "Empty Queue!";
	return data[_top];
}

template <typename T>
T AQueue<T>::pop() throw (const char*) {
	if (_top == _tail)
		throw "Empty Queue!";
	T& d = data[_top];
	_top = (_top+1) % _maxLength;
	return d;
}


template <typename T>
class LQueue : public Queue<T> {
		
	struct Node {
		T d;
		Node* left;
		Node* right;
	};
	
	long _length;
	Node* _head;
	Node* _tail;
	
public:
	LQueue();
	virtual long length() { return _length; }
	virtual void push(const T&) throw (const char*);
	virtual const T& top() throw (const char*);
	virtual T pop() throw (const char*);
};

template <typename T>
LQueue<T>::LQueue() {
	_head = _tail = 0;
	_length = 0;
}

template <typename T>
void LQueue<T>::push(const T& t) throw (const char*) {
	Node* p = new Node;
	p->d = t;
	p->left = p->right = 0;
	if (!_length)
		_head = _tail = p;
	else {
		_tail->right = p;
		p->left = _tail;
		_tail = p;
	}
	_length ++;
}

template <typename T>
const T& LQueue<T>::top() throw (const char*) {
	if (!_length)
		throw "Empty Queue!";
	return _head->d;
}

template <typename T>
T LQueue<T>::pop() throw (const char*) {
	if (!_length)
		throw "Empty Queue!";
	Node* p = _head;
	T d = p->d;
	_head = _head->right;
	delete p; 
	_length --;
	return d;
}

#endif
