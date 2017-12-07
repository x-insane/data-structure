#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct HaffNode {
	char c;
	int v;
	int _size;
	HaffNode* par;
	HaffNode() {
		v = 0;
		c = 0;
		par = 0;
		_size = 0;
	}
	HaffNode(int v, char c = 0) {
		this->v = v;
		this->c = c;
		par = 0;
		_size = 0;
	}
	int size() {
		if (!_size)
			_size = par ? 1 + par->size() : 1;
		return _size;
	}
};

struct HC {
	HaffNode* p;
	HC(HaffNode* p) {
		this->p = p;
	}
	friend bool operator<(const HC& a, const HC& b) {
		return a.p->v > b.p->v;
	}
};

int main() {
	int m;
	cin >> m;
	int charmap[256] {0};
	for (int i=0;i<m;++i) {
		int n;
		cin >> n;
		HaffNode* d = new HaffNode[n];
		priority_queue<HC> pq;
		vector<HaffNode*> gv;
		for (int j=0;j<n;++j) {
			int v;
			char c;
			cin >> c >> v;
			d[j].c = c;
			d[j].v = v;
			pq.push(HC(&d[j]));
		}
		while (pq.size() > 1) {
			HC a = pq.top();
			pq.pop();
			HC b = pq.top();
			pq.pop();
			HaffNode* p = new HaffNode(a.p->v + b.p->v);
			a.p->par = b.p->par = p;
			gv.push_back(p);
			pq.push(HC(p));
		}
		for (int j=0;j<n;++j)
			charmap[d[j].c] = d[j].size();
		string data;
		getline(cin, data);
		getline(cin, data);
		long size = 0;
		for (int j=0;j<data.length();++j)
			size += charmap[data[j]] - 1;
		cout << size << endl;
		delete[] d;
		for (int j=0;j<gv.size();++j)
			delete gv[j];
	}
	return 0;
}