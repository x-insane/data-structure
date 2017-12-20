#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i=0;i<T;++i) {
		int n, k;
		cin >> n >> k;
		int* data = new int[n];
		for (int j=0;j<n;++j)
			cin >> data[j];
		stable_sort(data+0, data+n);
		cout << data[k-1] << endl;
	}
	return 0;
}