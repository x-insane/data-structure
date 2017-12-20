#include <iostream>
using namespace std;

class HeapSort {
	int* d;
	int n;
private:
	void make_first_bigger(int& a, int& b) {
		if (a < b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
	}
	void sift_down(int i) {
		int l = 2*i+1;
		int r = 2*i+2;
		int m = 0;
		if (l < n && d[l] < d[i])
			m = -1;
		if (r < n && d[r] < d[i]) {
			if (m == 0 || (m == -1 && d[r] < d[l]))
				m = 1;
		}
		if (m == -1)
			make_first_bigger(d[l], d[i]);
		else if (m == 1)
			make_first_bigger(d[r], d[i]);
		if (2*l+1 < n)
			sift_down(l);
		if (2*r+1 < n)
			sift_down(r);
	}
public:
	HeapSort(int* data, int n) {
		d = data;
		this->n = n;
		for (int i=(n-1)/2;i>=0;i--)
			sift_down(i);
	}
	void print() {
		cout << d[0];
		for (int i=1;i<n;i++)
			cout << " " << d[i];
		cout << endl;
	}
	void sort() {
		int k = n;
		while (--n) {
			make_first_bigger(d[0], d[n]);
			sift_down(0);
		}
		n = k;
	}
};

int main() {
	int data[100000];
	int n = 0;
	while (cin >> data[n++]);
	HeapSort ts(data, --n);
	ts.print();
	ts.sort();
	ts.print();
	return 0;
}