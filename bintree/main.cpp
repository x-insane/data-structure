#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "bintree.h"
using namespace std;

void print(const int& d) {
	cout << d << " ";
}

int main() {
	
	freopen("output.txt", "w", stdout);

	srand(time(0));

	cout << "构造数据" << endl;
	BinNode<int>* head = new BinNode<int>(0);
	for (int i=1;i<256;++i)
		head->insert(i);

	cout << "层序输出" << endl;
	head->level_out(print);
	cout << endl;

	cout << "前序输出" << endl;
	head->preorder_out(print);
	cout << endl;

	cout << "中序输出" << endl;
	head->inorder_out(print);
	cout << endl;

	cout << "后序输出" << endl;
	head->postorder_out(print);
	cout << endl;

	cout << "高度：" << head->height() << endl;
	cout << "叶子数：" << head->leaf_num() << endl;

	delete head;
	head = 0;
	cout << "测试完成\n\n";

	fclose(stdout);
	return 0;
}
