#include <iostream>
#include <cstdio>
using namespace std;

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
		if (t < data)
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


void print(const int& d) {
	cout << d << " ";
}

int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;++i) {
		int tmp;
		cin >> tmp;
		BinNode<int>* head = new BinNode<int>(tmp);
		while(scanf(",%d", &tmp))
			head->insert(tmp);
		head->level_out(print);
		cout << endl;
		delete head;
	}
	return 0;
}