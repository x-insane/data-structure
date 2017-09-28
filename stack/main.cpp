#include <iostream>
#include "stack.h"
using namespace std; 

void test(Stack<int>& s) {
	try {
		int v;
		cout << "输出:"; 
		while (cin >> v) { // 非0则入栈，0则出栈 
			if (v)
				s.push(v);
			else
				cout << " " << s.pop();
		}
		cout << "\n剩余:";
		while (s.length())
			cout << " " << s.pop();	
	} catch (const char* e) {
		cout << "\n-----" << e << "-----\n";
	}	
}

int main() {
	
	freopen("output.txt", "w", stdout);
	
	AStack<int> a;
	LStack<int> b;
	
	freopen("input.txt", "r", stdin);
	cout << "----------Test AStack----------\n";
	test(a);
	cout << "\n----------AStack Okay----------\n\n";
	cin.clear();
	
	rewind(stdin);
	cout << "----------Test LStack----------\n";
	test(b);
	cout << "\n----------LStack Okay----------\n";
	cin.clear();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
