#include <iostream>
#include <vector>
using namespace std;

bool dfs_circle(vector<int>* d, bool* mark, int i) {
	for (int j=0;j<d[i].size();j++) {
		if (mark[d[i][j]])
			return true;
		else {
			mark[d[i][j]] = true;
			if (dfs_circle(d, mark, d[i][j]))
				return true;
			mark[d[i][j]] = false;
		}
	}
	return false;
}

int main()
{
	int m;
	cin >> m;
	for (int p=0;p<m;p++) {
		int n, e;
		cin >> n >> e;
		vector<int>* d = new vector<int>[n+1];
		bool* mark = new bool[n+1];
		for (int i=0;i<e;i++) {
			int a, b;
			cin >> a >> b;
			d[a].push_back(b);
		}
		bool circle = false;
		for (int i=1;!circle && i<=n;i++) {
			for (int j=1;j<=n;j++)
				mark[j] = false;
			mark[i] = true;
			circle = dfs_circle(d, mark, i);
		}
		if (circle)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		delete[] d;
		delete[] mark;
	}
	return 0;
}