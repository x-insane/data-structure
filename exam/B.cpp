#include <iostream>
using namespace std;

class Node {
public:
    Node(int elem, Node *left=NULL, Node *right=NULL) {
        this->elem = elem;
        this->left = left;
        this->right = right;
    }
    int elem;
    Node *left, *right;
};

class Tree {
public:
    Tree() {
        root = 0;
    }
    void insert(int elem) {
    	if (!root) {
    		root = new Node(elem);
    		return;
		}
        Node* p = root;
        while (true) {
        	if (p->elem > elem) {
        		if (p->left)
        			p = p->left;
        		else {
        			p->left = new Node(elem);
        			return;
				}
			} else {
				if (p->right)
        			p = p->right;
        		else {
        			p->right = new Node(elem);
        			return;
				}
			}
		}
    }
    void traverse(int *result) {
        int i = 0;
        traverse_help(root, result, i);
    }
    void traverse_help(Node* p, int *result, int& i) {
    	if (p->left)
    		traverse_help(p->left, result, i);
    	if (p->right)
    		traverse_help(p->right, result, i);
    	result[i++] = p->elem;
	}
    Node *root;
};

int main() {
    int M;
    cin >> M;
    while (M--) {
        int N;
        cin >> N;
        Tree tree;
        for(int i=0;i<N;i++) {
            int temp;
            cin >> temp;
            tree.insert(temp);
        }
        int *result = new int[N];
        tree.traverse(result);
        for(int i=0; i<N; i++)
            cout << result[i] << (i==N-1?'\n':' ');
        delete [] result;
    }
    return 0;
}