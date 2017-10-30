#include <iostream>
#include <sstream>
#include <cstring>
#include "lcrs.h"
using namespace std;

void flush() {
	// cin.clear();
	// cin.sync();
	cout << "> ";
}

template<typename Tree>
void test(Tree*) {
	GTNodeADT<int>* root = 0, *p = 0;
	string cmdstr;
	flush();
	bool conti = false;
	stringstream ss;
	while (conti || getline(cin, cmdstr)) {
		string cmd;
		if (!conti) {
			ss.clear();
			ss.str("");
			ss << cmdstr;
		}
		ss >> cmd;
		conti = false;
		if (cmd == "new") {
			int t;
			if (ss >> t) {
				if (root)
					delete root;
				p = root = new Tree(t);
			} else
				cout << "Wrong input value." << endl;
		} else if (!root) {
			cout << "There is no tree. Please new first." << endl;
			flush();
			continue;
		} else if (cmd == "print") {
			p->print();
		} else if (cmd == "insert") {
			string option;
			int t;
			if (ss >> option >> t) {
				if (option == "child")
					p->insertChild(t);
				else if (option == "next")
					p->insertSibling(t);
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
					GTNodeADT<int>* tmp = p->firstChild();
					if (tmp)
						p = tmp;
					else {
						cout << "This node has no child." << endl;
						flush();
						continue;
					}
				}
				else if (option == "next") {
					GTNodeADT<int>* tmp = p->next();
					if (tmp)
						p = tmp;
					else {
						cout << "This node has no right sibling." << endl;
						flush();
						continue;
					}
				}
				else if (option == "parent") {
					GTNodeADT<int>* tmp = p->parent();
					if (tmp)
						p = tmp;
					else {
						cout << "This node has no parent node." << endl;
						flush();
						continue;
					}
				}
				else if (option == "root")
					p = root;
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
	test((LCRSTNode<int>*)0);
	return 0;
}
