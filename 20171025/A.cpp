#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

int main() {
	int a, b;
	while (cin >> a >> b) {
		vector<int> v;
		int tmp;
		for (int i=0;i<a+b;++i) {
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		for (int j=0;j<a+b-1;++j)
			cout << v[j] << " ";
		if (!a && !b)
			cout << "NULL" << endl;
		else
			cout << v[a+b-1] << endl;
	}
	return 0;
}