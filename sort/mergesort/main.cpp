#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <sstream>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include "mergesort.h"
using namespace std;

#define TEST_GROUP_NUM 200
#define TEST_EACH_NUM 50
#define TEST_BIG_NUM 100000

void generate() {
	ofstream out("input.txt");
	srand(time(0));
	for (int i=0;i<TEST_GROUP_NUM;++i) {
		for (int j=0;j<TEST_EACH_NUM;++j)
			out << rand() % (TEST_EACH_NUM * 100) << " ";
		out << endl;
	}
	out.close();
}

void generate_big() {
	ofstream out("input-big.txt");
	srand(time(0));
	for (int i=0;i<TEST_BIG_NUM;++i)
		out << ((rand()+1)*(rand()+1)+1) % (TEST_BIG_NUM*100) << " ";
	out.close();
}

void testA() {
	clock_t a, b;
	a = clock();
	ifstream in("input.txt");
	ofstream out("outputA.txt");
	string s;
	while (getline(in, s)) {
		stringstream in(s);
		long d[TEST_EACH_NUM];
		memset(d, 0, TEST_EACH_NUM*sizeof(long));
		int n=0;
		long tmp;
		while (in >> tmp)
			d[n++] = tmp;
		mergesort(d, n);
		for (int i=0;i<n;++i)
			out << d[i] << " ";
		out << endl << endl;
	}
	in.close();
	out.close();
	b = clock();
	cout << "test array-based mergesort cost " << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
}

void testL() {
	clock_t a, b;
	a = clock();
	ifstream in("input.txt");
	ofstream out("outputL.txt");
	string s;
	while (getline(in, s)) {
		stringstream in(s);
		int tmp;
		Node<int>* head = 0, *p = 0;
		while (in >> tmp) {
			if (!head)
				p = head = new Node<int>(tmp);
			else
				p = p->append(tmp);
		}
		head = head->mergesort();
		while (head) {
			out << head->val() << " ";
			head = head->next();
		}
		out << endl;
	}
	in.close();
	out.close();
	b = clock();
	cout << "test linked mergesort cost " << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
}

void testA_big() {
	clock_t a, b;
	a = clock();
	ifstream in("input-big.txt");
	ofstream out("outputA-big.txt");
	long* d = new long[TEST_BIG_NUM];
	memset(d, 0, TEST_BIG_NUM*sizeof(long));
	int n = 0;
	long tmp;
	while (in >> tmp)
		d[n++] = tmp;
	mergesort(d, n);
	for (int i=0;i<n;++i)
		out << d[i] << " ";
	delete[] d;
	in.close();
	out.close();
	b = clock();
	cout << "test array-based mergesort with big data cost " << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
}

void testL_big() {
	clock_t a, b;
	a = clock();
	ifstream in("input-big.txt");
	ofstream out("outputL-big.txt");
	int tmp;
	Node<int>* head = 0, *p = 0;
	while (in >> tmp) {
		if (!head)
			p = head = new Node<int>(tmp);
		else
			p = p->append(tmp);
	}
	head = head->mergesort();
	while (head) {
		out << head->val() << " ";
		head = head->next();
	}
	in.close();
	out.close();
	b = clock();
	cout << "test linked mergesort with big data cost " << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
}

int main() {
	freopen("result.txt", "w", stdout);
	generate();
	generate_big();
	testA();
	testL();
	testA_big();
	testL_big();
	return 0;
}
