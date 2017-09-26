#include <iostream>
#include <cstdio>
#include "list.h"
using namespace std;

void print(List<int>& a) {
	cout << "��" << a.length() << "����";
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
	cout << "�ڵ�һ��9ǰ����һ��150\n";
	print(a);
	
	a.remove(a.find(150, a.next(a.find(150))));
	cout << "ɾ���˵ڶ���150\n";
	print(a);
	
	cout << "ɾ�������еĹ�" << a.remove(1) << "��1\n";
	print(a);
	
	a[a.find(150)] = 510;
	cout << "�ѵ�һ��150�ĳ���510\n";
	print(a);
	
	a.reverse();
	cout << "���������з���\n";
	print(a);
}

int main() {
	
	freopen("list.in", "r", stdin); // �������� 
	AList<int> a;
	cout << "----------����AList----------\n";
	test(a);
	cout << "----------AList���----------\n\n";
	cin.clear();
	
	rewind(stdin);
	LList<int> b;
	cout << "----------����LList----------\n";
	test(b);
	cout << "----------LList���----------\n\n";
	cin.clear();

	return 0;
}
