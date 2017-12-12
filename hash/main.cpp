#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include "dict.h"
using namespace std;

void generate(int* d, int n) {
	for (int i=0;i<n;++i)
		d[i] = rand();
}

long test_insert(Dict<string, int>& dict, int* d, int n) {
	clock_t begin = clock();
	for (int i=0;i<n;i++) {
		char num[8];
		sprintf(num, "%d", d[i]);
		dict[num] = i;
	}
	clock_t end = clock();
	return (end - begin) * 1000 / CLOCKS_PER_SEC;
}

long test_remove(Dict<string, int>& dict, int* d, int n) {
	clock_t begin = clock();
	for (int i=0;i<n;i++) {
		char num[8];
		sprintf(num, "%d", d[i]);
		dict.remove(num);
	}
	clock_t end = clock();
	return (end - begin) * 1000 / CLOCKS_PER_SEC;
}

int main() {
	freopen("result.txt", "w", stdout);
	srand(time(0));
	int n = 1000000;
	int* data = new int[n];
	generate(data, n);
	Dict<string, int> dict(0, n + n/10);
	cout << "n = " << n << endl;
	cout << "linear probe: insert " << test_insert(dict, data, n) << " ms & ";
	cout << "remove " << test_remove(dict, data, n) << " ms" << endl;
	dict.clear();
	dict.setProbe(2);
	cout << "quadratic probe: insert " << test_insert(dict, data, n) << " ms & ";
	cout << "remove " << test_remove(dict, data, n) << " ms" << endl;
	dict.clear();
	dict.setProbe(3);
	cout << "random probe: insert " << test_insert(dict, data, n) << " ms & ";
	cout << "remove " << test_remove(dict, data, n) << " ms" << endl;
	return 0;
}
