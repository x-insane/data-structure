#include <iostream>
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
	void print() {
		for (int i=0;i<size;i++) {
			if (data[i] && !data[i]->empty)
				cout << i << " " << data[i]->key << endl;
		}
	}
};

int main() {
	int size;
	cin >> size;
	Dict<int, int> dict(size);
	int data;
	while (cin >> data)
		dict[data] = 1;
	dict.print();
	return 0;
}