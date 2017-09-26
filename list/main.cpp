#include <iostream>
#include <cstdio>
#include "list.h"
using namespace std;

void print(List<int>& a) {
	cout << "共" << a.length() << "个：";
	for (POSITION pos = a.head();a.valid_pos(pos);pos = a.next(pos))
		cout << a[pos] << " ";
	cout << "\n\n";
}

void test(List<int>& a) {
	
	int v;
	while(cin >> v) {
		a.append(v);
	}
	print(a);
	
	a.insert(a.find(9), 150);
	cout << "在第一个9前插入一个150\n";
	print(a);
	
	a.remove(a.find(150, a.next(a.find(150))));
	cout << "删除了第二个150\n";
	print(a);
	
	cout << "删除了所有的共" << a.remove(1) << "个1\n";
	print(a);
	
	a[a.find(150)] = 510;
	cout << "把第一个150改成了510\n";
	print(a);
	
	a.reverse();
	cout << "将整个序列反向\n";
	print(a);
}

int main() {
	
	freopen("list.in", "r", stdin); // 测试数据 
	AList<int> a;
	cout << "----------测试AList----------\n";
	test(a);
	cout << "----------AList完成----------\n\n";
	cin.clear();
	
	rewind(stdin);
	LList<int> b;
	cout << "----------测试LList----------\n";
	test(b);
	cout << "----------LList完成----------\n\n";
	cin.clear();

	return 0;
}
