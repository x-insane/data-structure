#include <iostream>
#include <string>
using namespace std;

int main() {
	int nn;
	cin >> nn;
	for (int i=0;i<nn;i++) {
		int n, m, k;
		cin >> n >> m >> k;
		int result = 0;
		if (k > m) {
			cout << 0 << endl;
			continue;
		}
		for (int j=0;j<n;j++) {
			int tmp;
			cin >> tmp;
			if (tmp % m == k)
				result ++;
		}
		cout << result << endl;
	}
	return 0;
}