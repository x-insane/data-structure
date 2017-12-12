#include "dict.h"
#include <string>
using namespace std;

int Hash(string key, int size) {
	int sum = 0;
	int n = key.length();
	for (int i=0;i<n;++i)
		sum += (sum*256 + key[i]) % size;
	return sum % size;
}

int Hash(int key, int size) {
	return key % size;
}
