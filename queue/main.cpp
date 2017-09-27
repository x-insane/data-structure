#include <iostream>
#include "queue.h"
using namespace std;

void test(Queue<int>& s) {
	try {
		for (int i=1;i<=106;++i) {
			if (i%3)
				s.push(i);
			else
				s.pop();
		}
		cout << "¹²" << s.length() << "¸ö: ";
		while(s.length())
			cout << s.pop() << " ";
	} catch (const char* e) {
		cout << "\n-----" << e << "-----\n";
	}
		
}

int main() {
	AQueue<int> a;
	LQueue<int> b;
	
	cout << "----------Test AQueue----------\n";
	test(a);
	cout << "\n----------AQueue Okay----------\n\n";
	
	cout << "----------Test LQueue----------\n";
	test(b);
	cout << "\n----------LQueue Okay----------\n";
	
	return 0;
}
