// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/tree/main/PRACTICE/2526-2%20Stack%20Queue/Alternating%20Current to know the problem

#include <iostream>
#include <cstring>
using namespace std;

// Define structures
struct Node {
	char data;
	Node* pNext;
};

struct List {
	Node* pHead;
};

// Functions related to nodes
Node* CreateNode(char data) {
	Node* newnode = new Node();
	newnode->data = data;
	newnode->pNext = nullptr;
	return newnode;
}

// I add nodes to head of the linked list so that I can pop an element out of the list easily
void AddHead(List& l, char data) {
	Node* node = CreateNode(data);

	if (l.pHead == nullptr) {
		l.pHead = node;
		return;
	}
	else {
		// l.pHead is pointing at a node. A node comes in, we need to tell the new node to point to the node where l.pHead is pointing.
		node->pNext = l.pHead;
		l.pHead = node; // Modify l.pHead;
	}
}

void deleteNode(List& l, char comparedata) {
	Node* temp = nullptr;
	if (l.pHead == nullptr) {
		AddHead(l, comparedata);
	}
	else {
		if (l.pHead->data == comparedata) {
			temp = l.pHead;
			l.pHead = l.pHead->pNext;
			delete temp;
			temp = nullptr;
		}
		else {
			AddHead(l, comparedata);
		}
	}
}

void Init(List& l) {
	l.pHead = nullptr;
}

void deleteList(List& l) {
	Node* cur = l.pHead;
	while (l.pHead != nullptr) {
		l.pHead = l.pHead->pNext;
		delete cur;
		cur = l.pHead;
	}
}

int main() {
	List l;
	Init(l);

	char* str = new char[100001];
	cin.getline(str, 100001);

	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		deleteNode(l, str[i]);
	}

	if (l.pHead == nullptr) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	deleteList(l);

	return 0;
}