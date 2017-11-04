#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include "lcrs.h"
#include "ldct.h"
#include "adct.h"
using namespace std;

void flush() {
	// cin.clear();
	// cin.sync();
	cout << "> ";
}

template<typename T>
void test(GTreeADT<T>* tree) {
	string cmdstr;
	flush();
	bool conti = false;
	stringstream ss;
	while (conti || getline(cin, cmdstr)) {
		string cmd;
		if (!conti) {
			ss.clear();
			ss.str("");
			if (cmdstr == "") {
				flush();
				continue;
			}
			ss << cmdstr;
		}
		ss >> cmd;
		conti = false;
		if (cmd == "new") {
			int t;
			if (ss >> t) {
				tree->newRoot(t);
			} else
				cout << "Wrong input value." << endl;
		} else if (!tree->root()) {
			cout << "There is no tree. Please new first." << endl;
			flush();
			continue;
		} else if (cmd == "print") {
			tree->print();
		} else if (cmd == "insert") {
			string option;
			int t;
			if (ss >> option >> t) {
				if (option == "child")
					tree->insertChild(t);
				else if (option == "next")
					tree->insertSibling(t);
				else {
					cout << "Wrong input. Please type 'insert child/next value'" << endl;
					flush();
					continue;
				}
			} else {
				cout << "Wrong input. Please type 'insert child/next value'" << endl;
				flush();
				continue;
			}
		} else if (cmd == "move") {
			string option;
			if (ss >> option) {
				if (option == "child") {
					if (!tree->moveFirstChild()) {
						cout << "This node has no child." << endl;
						flush();
						continue;
					}
				}
				else if (option == "next") {
					if (!tree->moveNext()) {
						cout << "This node has no right sibling." << endl;
						flush();
						continue;
					}
				}
				else if (option == "parent") {
					if (!tree->moveParent()) {
						cout << "This node has no parent node." << endl;
						flush();
						continue;
					}
				}
				else if (option == "root")
					tree->moveRoot();
				else {
					cout << "Wrong input. Please type 'move root/parent/child/next'" << endl;
					flush();
					continue;
				}
			} else {
				cout << "Wrong input. Please type 'move root/parent/child/next'" << endl;
				flush();
				continue;
			}
		} else if (cmd == "remove") {
			string option;
			if (ss >> option) {
				if (option == "child") {
					if (tree->firstChild())
						tree->removeFirstChild();
					else
						cout << "This node has no child." << endl;
				}
				else if (option == "next") {
					if (tree->next())
						tree->removeNextSibling();
					else
						cout << "This node has no right sibling." << endl;
				}
				else {
					cout << "Wrong input. Please type 'remove child/next'" << endl;
					flush();
					continue;
				}
			} else {
				cout << "Wrong input. Please type 'remove child/next'" << endl;
				flush();
				continue;
			}
		} else if (cmd == "exit")
			break;
		else
			cout << "Wrong command. Valid command: new print move insert" << endl;
		if (ss >> cmd && cmd == "&") {
			conti = true;
			continue;
		}
		flush();
	}
	cout << "Bye.";
}

int main() {
	// freopen("in.txt", "r", stdin); // input data, 3 times
	LCRSTree<int> t1;
	LDCTree<int> t2;
	ADCTree<int> t3;
	cout << "-------------TEST 1--------------" << endl;
	test(&t1);
	cout << endl << endl << "-------------TEST 2--------------" << endl;
	test(&t2);
	cout << endl << endl << "-------------TEST 3--------------" << endl;
	test(&t3);
	return 0;
}
