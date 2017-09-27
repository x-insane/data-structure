#include <iostream>
#include "stack.h"
using namespace std; 

void test(Stack<int>& s) {
	for (int i=1;i<=105;++i)
		s.push(i);
	while(s.length())
		cout << s.pop() << " ";
}

int main() {
	AStack<int> a;
	LStack<int> b;
	
	cout << "----------Test AStack----------\n";
	test(a);
	cout << "\n----------AStack Okay----------\n\n";
	
	cout << "----------Test LStack----------\n";
	test(b);
	cout << "\n----------LStack Okay----------\n\n";
	
	return 0;
}
