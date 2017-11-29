#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int i;
	char c;
};

void sort(Node* d, int n) {
	for (int i=0;i<n-1;i++) {
		for (int j=i+1;j<n;j++) {
			if (d[i].c > d[j].c) {
				char t = d[i].c;
				d[i].c = d[j].c;
				d[j].c = t;
			}
		}
	}
}

int main() {
	string s;
	while (getline(cin, s)) {
		Node* d = new Node[s.length()];
		int n = 0;
		for (int j=0;j<s.length();j++) {
			if (s[j] >= 'A' && s[j] <= 'Z') {
				d[n].i = j;
				d[n].c = s[j];
				n ++;
			}
		}
		sort(d, n);
		for (int j=0;j<n;j++)
			s[d[j].i] = d[j].c;
		cout << s << endl;
		delete[] d;
	}
	return 0;
}