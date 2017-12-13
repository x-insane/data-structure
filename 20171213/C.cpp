#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int Hash(int key, int size) {
	return key % size;
}

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
	Node** data;
	Value deft;
public:
	Dict(int n = 10000) {
		size = n;
		data = new Node*[size];
		for (int i=0;i<size;++i)
			data[i] = 0;
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
			n = (start + i) % size;
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
	int indexKey(const Key& key) {
		int n = Hash(key, size), i = 0;
		const int start = n;
		Node* p = 0;
		while (i++ < size && data[n]) {
			if (data[n]->empty)
				p = p ? p : data[n];
			else if (data[n]->key == key)
				return n;
			n = (start + i) % size;
		}
		return -1;
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

int main() {
	int size;
	cin >> size;
	Dict<int, int> dict(size);
	string line;
	getline(cin, line);
	getline(cin, line);
	stringstream lin(line);
	int data;
	while (lin >> data)
		dict[data] = 1;
	getline(cin, line);
	stringstream lin2(line);
	while (lin2 >> data)
		dict.remove(data);
	getline(cin, line);
	stringstream lin3(line);
	while (lin3 >> data) {
		int index = dict.indexKey(data);
		if (index == -1)
			cout << "NO" << endl;
		else
			cout << index << endl;
	}
	return 0;
}