#include <iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	for (int i=0;i<m;++i) {
		int n, e, s;
		cin >> n >> e >> s;
		bool d[100][100];
		for (int o=0;o<n;++o)
			for (int k=0;k<n;++k)
				d[o][k] = false;
		for (int j=0;j<e;++j) {
			int a, b;
			cin >> a >> b;
			d[a][b] = d[b][a] = true;
		}
		int queue[100];
		bool mark[100];
		for (int o=0;o<n;++o)
			mark[o] = false;
		int l = 0, r = 1;
		queue[0] = s;
		mark[s] = true;
		int out = 1;
		while (l < r) {
			int t = queue[l++];
			cout << t;
			if (out < n)
				cout << " ";
			out ++;
			for (int k=0;k<n;++k) {
				if (d[t][k] && !mark[k]) {
					queue[r++] = k;
					mark[k] = true;
				}
			}
		}
		cout << endl;
	}
	return 0;
}