#ifndef __DICT_H_IDJ4HG__
#define __DICT_H_IDJ4HG__

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int Hash(string key, int size);
int Hash(int key, int size);

template <typename Key, typename Value>
class Dict {
	struct Node {
		Key key;
		Value value;
		bool empty;
		Node(const Key& k, const Value& v) {
			key = k;
			value = v;
			empty = false;
		}
		Node(const Key& k) {
			key = k;
			empty = false;
		}
	};
	int size;
	int probe;
	Node** data;
	Value deft;
public:
	Dict(int n = 10000) {
		size = n;
		probe = 1;
		data = new Node*[size];
		for (int i=0;i<size;++i)
			data[i] = 0;
		srand(time(0));
	}
	Dict(const Value& v, int n = 10000) {
		size = n;
		deft = v;
		probe = 1;
		data = new Node*[size];
		for (int i=0;i<size;++i)
			data[i] = 0;
		srand(time(0));
	}
	void setProbe(int type = 1) {
		probe = type;
	}
	Value& operator[](const Key& key) {
		int n = Hash(key, size), i = 0;
		const int start = n;
		Node* p = 0;
		while (i++ < size && data[n]) {
			if (data[n]->empty)
				p = p ? p : data[n];
			else if (data[n]->key == key)
				return data[n]->value;
			if (probe == 1)
				n = (start + i) % size;
			else if (probe == 2)
				n = (start + i*i) % size;
			else
				n = (start + rand()) % size; // 无法保证完整历遍
		}
		if (p) {
			p->key = key;
			p->empty = false;
			return p->value;
		}
		if (!data[n]) {
			data[n] = new Node(key, deft);
			return data[n]->value;
		}
		throw "Dict overflow!";
	}
	void remove(const Key& key) {
		int n = Hash(key, size), i = 0;
		Node* p = 0;
		while (i++ < size && data[n]) {
			if (!data[n]->empty && data[n]->key == key) {
				data[n]->empty = true;
				data[n]->value = deft;
				return;
			}
			n = (n+1) % size;
		}
	}
	void clear() {
		for (int i=0;i<size;++i) {
			if (data[i]) {
				delete data[i];
				data[i] = 0;
			}
		}
	}
};

#endif
