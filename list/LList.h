#ifdef __LIST_D2G3HF8__
#ifndef __LLIST_V64F8FG__
#define __LLIST_V64F8FG__

// 此文件是为了更清晰的结构分离开写，附属于list.h，不可单独引用

template <typename T>
LList<T>::LList() {
	_head = _tail = 0;
	_length = 0;
}

template <typename T>
void LList<T>::append(const T& t) {
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
bool LList<T>::insert(const POSITION& pos, const T& t) {
	if (!pos.pointer)
		return false;
	Node* p = new Node;
	p->d = t;
	p->left = p->right = 0;
	if (pos.pointer == _head) {
		p->right = _head;
		_head->left = p;
		_head = p;
	} else {
		Node* now = (Node*)pos.pointer;
		now->left->right = p;
		p->left = now->left;
		p->right = now;
		now->left = p;
	}
	_length ++;
	return true;
}

template <typename T>
bool LList<T>::remove(const POSITION& pos) {
	if (!pos.pointer)
		return false;
	Node* now = (Node*)pos.pointer;
	now->left->right = now->right;
	now->right->left = now->left;
	delete now;
	_length --;
	return true;
}

template <typename T>
long LList<T>::remove(const T& t) {
	long n = 0;
	for (Node* p=_head;p;) {
		if (p->d == t) {
			POSITION pos;
			pos.pointer = p;
			remove(pos);
			p = p->right;
			n ++;
		} else
			p = p->right;
	}
	return n;
}

template <typename T>
void LList<T>::clear() {
	if (!_length)
		return;
	for (Node* p=_head;p;p=p->right) {
		if (p->left)
			delete p->left;
	}
	delete _tail;
	_head = _tail = 0;
	 _length = 0;
}

template <typename T>
T& LList<T>::operator[](const POSITION& pos) {
	return ((Node*)pos.pointer)->d;
}

template <typename T>
List<T>& LList<T>::reverse() {
	if (!_length)
		return *this;
	for (Node* p=_head;p;p=p->right) {
		if (p->left) {
			Node* tmp = p->left->left;
			p->left->left = p->left->right;
			p->left->right = tmp;
		}
	}
	_tail->right = _tail->left;
	_tail->left = 0;
	Node* tmp = _head;
	_head = _tail;
	_tail = tmp;
	return *this;
}

template <typename T>
POSITION LList<T>::next(const POSITION& pos) {
	POSITION r;
	r.pointer = 0;
	if (pos.pointer)
		r.pointer = ((Node*)pos.pointer)->right;
	return r;
}

template <typename T>
POSITION LList<T>::find(const T& t, const POSITION& start) {
	POSITION pos;
	pos.pointer = 0;
	if (!start.pointer)
		return pos;
	for (Node* p=(Node*)start.pointer;p;p=p->right) {
		if (p->d == t) {
			pos.pointer = p;
			break;
		}
	}
	return pos;
}

#endif
#endif
