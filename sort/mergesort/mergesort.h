#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

template<typename T>
void mergesort(T* d, int n) {
	if (n == 1)
		return;
	int mid = n / 2;
	mergesort(d, mid);
	mergesort(d+mid, n-mid);
	T* t = new T[n];
	int i=0, j=mid, k=0;
	while (k<n) {
		if (i == mid || (j<n && d[i]>d[j]))
			t[k++] = d[j++];
		else
			t[k++] = d[i++];
	}
	for (k=0;k<n;++k)
		d[k] = t[k];
	delete[] t;
}

template<typename T>
class Node {
protected:
	T d;
	Node<T>* left;
	Node<T>* right;
protected:

public:
	Node(const T& data) {
		d = data;
		left = right = 0;
	}
	Node<T>* append(const T& data) {
		Node<T>* tmp = right;
		right = new Node<T>(data);
		right->left = this;
		right->right = tmp;
		if (tmp)
			tmp->left = right;
		return right;
	}
	Node<T>* append(Node<T>* next) {
		Node<T>* tmp = right;
		right = next;
		right->left = this;
		right->right = tmp;
		if (tmp)
			tmp->left = next;
		return right;
	}
public:
	T val() const {
		return d;
	}
	Node<T>* next() const {
		return right;
	}
	Node<T>* mergesort() {
		Node<T>* head = this;
		if (!head->right)
			return head;
		Node<T>* p = head, *mid = head;
		while (p && p->right) {
			p = p->right->right;
			mid = mid->right;
		}
		mid->left->right = 0;
		mid->left = 0;
		head = head->mergesort();
		mid = mid->mergesort();
		p = 0;
		Node<T>* h = 0;
		if (head->d > mid->d) {
			p = h = mid;
			mid = mid->right;
		} else {
			p = h = head;
			head = head->right;
		}
		p->right = 0;
		Node<T>* tmp;
		while (head || mid) {
			if (!head || (mid && head->d > mid->d)) {
				tmp = mid;
				mid = mid->right;
			} else {
				tmp = head;
				head = head->right;
			}
			p = p->append(tmp);
		}
		return h;
	}
};

#endif