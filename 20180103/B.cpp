#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	for (int p=0;p<m;p++) {
		int n, e;
		cin >> n >> e;
		int* d = new int[n+1];
		for (int i=1;i<=n;i++)
			d[i] = 0;
		for (int i=0;i<e;i++) {
			int tmp;
			cin >> tmp >> tmp;
			d[tmp] ++;
		}
		int max = 0;
		for (int i=1;i<=n;i++) {
			if (d[i] > max)
				max = d[i];
		}
		cout << max << endl;
		delete[] d;
	}
	return 0;
}