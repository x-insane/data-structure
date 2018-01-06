#include <iostream>
using namespace std;

class Node {
public:
    Node(int elem=0, Node *next=NULL) {
        this->elem = elem;
        this->next = next;
    }
    int elem;
    Node *next;
};

class List{
public:
    List() {
        head = tail = 0;
    }
    void append(int elem) {
    	if (!head)
    		head = tail = new Node(elem);
    	else {
    	    tail->next = new Node(elem);
	        tail = tail->next;	
		}
    }
    Node *head, *tail;
};

void merge(List &list1, List &list2, List &merged) {
    Node* i = list1.head, *j = list2.head;
    bool a = true, b = true;
    while ((i == list1.tail || a) && (j == list2.tail || b)) {
		if (i == list1.tail)
			a = false;
		if (j == list2.tail)
			b = false;
    	if (i->elem < j->elem) {
    		merged.append(i->elem);
    		i = i->next;
		} else {
			merged.append(j->elem);
    		j = j->next;
		}
	}
	if (i == list1.tail || a) {
		while (i) {
			merged.append(i->elem);
    		i = i->next;
		}
	}
	if (j == list2.tail || b) {
		while (j) {
			merged.append(j->elem);
    		j = j->next;
		}
	}
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int N1, N2;
        cin >> N1 >> N2;
        List list1, list2;
        for(int i=0; i<N1; i++) {
            int temp;
            cin >> temp;
            list1.append(temp);
        }
        for(int i=0; i<N2; i++) {
            int temp;
            cin >> temp;
            list2.append(temp);
        }
        List merged;
        merge(list1, list2, merged);
        Node *node = merged.head;
        while (node) {
            cout << node->elem << (node->next?' ':'\n');
            node = node->next;
        }
    }
    return 0;
}