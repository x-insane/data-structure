#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i=0;i<n;i++) {
		vector<int> v;
		getline(cin, s);
		stringstream in(s);
		int tmp;
		while (in >> tmp)
			v.push_back(tmp);
		int nn = 0;
		int last = v[v.size()-1];
		for (int j=0;j<v.size()-1;j++) {
			if (v[j] < last)
				nn ++;
		}
		cout << nn << endl;
	}
	return 0;
}