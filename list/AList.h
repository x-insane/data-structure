#ifdef __LIST_D2G3HF8__
#ifndef __ALIST_JU7G6DE__
#define __ALIST_JU7G6DE__

// 此文件是为了更清晰的结构分离开写，附属于list.h，不可单独引用

template <typename T>
AList<T>::AList() {
	data = new T[_initialSize];
	_size = _initialSize;
	_length = 0;
}

template <typename T>
void AList<T>::swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void AList<T>::allocate() {
	T* nd = new T[_size + _stepSize];
	for (long i=0;i<_length;++i)
		nd[i] = data[i];
	delete[] data;
	data = nd;
	_size += _stepSize;
}

template <typename T>
void AList<T>::append(const T& t) {
	if (_size == _length)
		allocate();
	data[_length++] = t;
}

template <typename T>
bool AList<T>::insert(const POSITION& pos, const T& t) {
	if (pos.index < 0 || pos.index >= _length)
		return false;
	if (_size == _length)
		allocate();
	for (long i=_length;i>pos.index;--i)
		data[i] = data[i-1];
	data[pos.index] = t;
	_length ++;
	return true;
}

template <typename T>
bool AList<T>::remove(const POSITION& pos) {
	if (pos.index < 0 || pos.index >= _length)
		return false;
	for (long i=pos.index;i<_length-1;++i)
		data[i] = data[i+1];
	_length --;
	return true;
}

template <typename T>
long AList<T>::remove(const T& t) {
	long n = 0;
	for (long i=0;i<_length;++i) {
		if (data[i] == t) {
			POSITION pos;
			pos.index = i;
			remove(pos);
			i --;
			n ++;
		}
	}
	return n;
}

template <typename T>
void AList<T>::clear() {
	delete[] data;
	data = new T[_initialSize];
	_size = _initialSize;
	_length = 0;
}

template <typename T>
T& AList<T>::operator[](const POSITION& pos) {
//	if (pos.index < 0 || pos.index >= _length)
//		return T(-1);
	return data[pos.index];
}

template <typename T>
List<T>& AList<T>::reverse() {
	for (long i=0;i<_length/2;++i)
		swap(data[i], data[_length-i-1]);
	return *this;
}

template <typename T>
POSITION AList<T>::next(const POSITION& pos) {
	POSITION r;
	if (pos.index < 0 || pos.index >= _length)
		r.index = -1;
	else
		r.index = pos.index + 1;
	return r;
}

template <typename T>
POSITION AList<T>::find(const T& t, const POSITION& start) {
	POSITION pos;
	pos.index = -1;
	if (start.index < 0 || start.index >= _length)
		return pos;
	for (long i=start.index;i<_length;++i) {
		if (data[i] == t) {
			pos.index = i;
			break;
		}
	}
	return pos;
}

#endif
#endif
