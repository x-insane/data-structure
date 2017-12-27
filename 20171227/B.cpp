#include <iostream>
using namespace std;

void DFS(bool d[][100], bool* mark, int t, int n, int& out) {
	cout << t;
	if (out < n)
		cout << " ";
	out ++;
	for (int k=0;k<n;++k) {
		if (d[t][k] && !mark[k]) {
			mark[k] = true;
			DFS(d, mark, k, n, out);
		}
	}
}

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
		bool mark[100];
		for (int o=0;o<n;++o)
			mark[o] = false;
		int out = 1;
		mark[s] = true;
		DFS(d, mark, s, n, out);
		cout << endl;
	}
	return 0;
}