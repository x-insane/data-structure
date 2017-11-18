#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <sstream>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include "quicksort.h"
using namespace std;

#define TEST_GROUP_NUM 200
#define TEST_EACH_NUM 1000
#define TEST_BIG_NUM 10000000

void generate() {
	ofstream out("data/input.txt");
	srand(time(0));
	for (int i=0;i<TEST_GROUP_NUM;++i) {
		for (int j=0;j<TEST_EACH_NUM;++j)
			out << rand() % (TEST_EACH_NUM * 100) << " ";
		out << endl;
	}
	out.close();
}

void generate_big() {
	ofstream out("data/input-big.txt");
	srand(time(0));
	for (int i=0;i<TEST_BIG_NUM;++i)
		out << ((rand()+1)*(rand()+1)+1) % (TEST_BIG_NUM*100) << " ";
	out.close();
}

void test() {
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input.txt");
		ofstream out("data/output.txt");
		string s;
		while (getline(in, s)) {
			stringstream in(s);
			long d[TEST_EACH_NUM];
			memset(d, 0, TEST_EACH_NUM*sizeof(long));
			int n=0;
			long tmp;
			while (in >> tmp)
				d[n++] = tmp;
			qsort(d, n);
			for (int i=0;i<n;++i)
				out << d[i] << " ";
			out << endl << endl;
		}
		in.close();
		out.close();
		b = clock();
		cout << "quicksort: " << (b-a)*1000/CLOCKS_PER_SEC << " ms & ";
	}
	
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input-big.txt");
		ofstream out("data/output-big.txt");
		long* d = new long[TEST_BIG_NUM];
		memset(d, 0, TEST_BIG_NUM*sizeof(long));
		int n = 0;
		long tmp;
		while (in >> tmp)
			d[n++] = tmp;
		qsort(d, n);
		for (int i=0;i<n;++i)
			out << d[i] << " ";
		delete[] d;
		in.close();
		out.close();
		b = clock();
		cout << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
	}
}

void test_a() {
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input.txt");
		ofstream out("data/output-a.txt");
		string s;
		while (getline(in, s)) {
			stringstream in(s);
			long d[TEST_EACH_NUM];
			memset(d, 0, TEST_EACH_NUM*sizeof(long));
			int n=0;
			long tmp;
			while (in >> tmp)
				d[n++] = tmp;
			qsort_a(d, n);
			for (int i=0;i<n;++i)
				out << d[i] << " ";
			out << endl << endl;
		}
		in.close();
		out.close();
		b = clock();
		cout << "quicksort-a: " << (b-a)*1000/CLOCKS_PER_SEC << " ms & ";
	}
	
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input-big.txt");
		ofstream out("data/output-big-a.txt");
		long* d = new long[TEST_BIG_NUM];
		memset(d, 0, TEST_BIG_NUM*sizeof(long));
		int n = 0;
		long tmp;
		while (in >> tmp)
			d[n++] = tmp;
		qsort_a(d, n);
		for (int i=0;i<n;++i)
			out << d[i] << " ";
		delete[] d;
		in.close();
		out.close();
		b = clock();
		cout << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
	}
}

void test_b(int threshold = 6) {
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input.txt");
		char title[100];
		sprintf(title, "data/output-b-%d.txt", threshold);
		ofstream out(title);
		string s;
		while (getline(in, s)) {
			stringstream in(s);
			long d[TEST_EACH_NUM];
			memset(d, 0, TEST_EACH_NUM*sizeof(long));
			int n=0;
			long tmp;
			while (in >> tmp)
				d[n++] = tmp;
			qsort_b(d, n, threshold);
			for (int i=0;i<n;++i)
				out << d[i] << " ";
			out << endl << endl;
		}
		in.close();
		out.close();
		b = clock();
		cout << "quicksort-b-" << threshold << ": " << (b-a)*1000/CLOCKS_PER_SEC << " ms & ";
	}
	
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input-big.txt");
		ofstream out("data/output-big-b.txt");
		long* d = new long[TEST_BIG_NUM];
		memset(d, 0, TEST_BIG_NUM*sizeof(long));
		int n = 0;
		long tmp;
		while (in >> tmp)
			d[n++] = tmp;
		qsort_b(d, n, threshold);
		for (int i=0;i<n;++i)
			out << d[i] << " ";
		delete[] d;
		in.close();
		out.close();
		b = clock();
		cout << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
	}
}

void test_c() {
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input.txt");
		ofstream out("data/output-c.txt");
		string s;
		while (getline(in, s)) {
			stringstream in(s);
			long d[TEST_EACH_NUM];
			memset(d, 0, TEST_EACH_NUM*sizeof(long));
			int n=0;
			long tmp;
			while (in >> tmp)
				d[n++] = tmp;
			qsort_c(d, n);
			for (int i=0;i<n;++i)
				out << d[i] << " ";
			out << endl << endl;
		}
		in.close();
		out.close();
		b = clock();
		cout << "quicksort-c: " << (b-a)*1000/CLOCKS_PER_SEC << " ms & ";
	}
	
	{
		clock_t a, b;
		a = clock();
		ifstream in("data/input-big.txt");
		ofstream out("data/output-big-c.txt");
		long* d = new long[TEST_BIG_NUM];
		memset(d, 0, TEST_BIG_NUM*sizeof(long));
		int n = 0;
		long tmp;
		while (in >> tmp)
			d[n++] = tmp;
		qsort_c(d, n);
		for (int i=0;i<n;++i)
			out << d[i] << " ";
		delete[] d;
		in.close();
		out.close();
		b = clock();
		cout << (b-a)*1000/CLOCKS_PER_SEC << " ms" << endl;
	}
}

int main() {
	freopen("data/result.txt", "w", stdout);
	generate();
	generate_big();
	test();
	test_a();
	for (int i=3;i<9;++i)
		test_b(i);
	test_c();
	return 0;
}
