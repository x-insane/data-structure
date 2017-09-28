#include <iostream>
#include "queue.h"
using namespace std;

void test(Queue<int>& s) {
	try {
		int v;
		cout << "���:"; 
		while (cin >> v) { // ��0����ӣ�0�����
			if (v)
				s.push(v);
			else
				cout << " " << s.pop();
		}
		cout << "\nʣ��:";
		while (s.length())
			cout << " " << s.pop();
	} catch (const char* e) {
		cout << "\n-----" << e << "-----\n";
	}
		
}

int main() {
	
	freopen("output.txt", "w", stdout);
	
	AQueue<int> a;
	LQueue<int> b;
	
	freopen("input.txt", "r", stdin);
	cout << "----------Test AQueue----------\n";
	test(a);
	cout << "\n----------AQueue Okay----------\n\n";
	cin.clear();
	
	rewind(stdin);
	cout << "----------Test LQueue----------\n";
	test(b);
	cout << "\n----------LQueue Okay----------\n";
	cin.clear();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
