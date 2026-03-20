// Problem: Given two linked lists. Merge them into a linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->pNext = nullptr;

    return newnode;
}

void AddNode(Node* &pHead, int data) {
    Node* node = CreateNode(data);
    Node* temp = pHead;

    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    while (temp->pNext != nullptr) {
        temp = temp->pNext;
    }

    temp->pNext = node;
}

void deleteList(Node* &pHead) {
    Node* cur = pHead;
    while (pHead != nullptr) {
        pHead = pHead->pNext;
        delete cur;
        cur = pHead;
    }
    cur = nullptr;
}

void printList(Node* pHead) {
    Node* cur = pHead;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->pNext;
    }
}

void Init(List& l) {
    l.pHead = nullptr;
}

int main() {
    List l;
    List l2;

    Init(l);
    Init(l2);

    // Input list 1
    int firstL_len; cin >> firstL_len;
    int m;
    for (int i = 0; i < firstL_len; i++) {
        cin >> m;
        AddNode(l.pHead, m);
    }

    // Input list 2
    int secondL_len; cin >> secondL_len;
    for (int i = 0; i < secondL_len; i++) {
        cin >> m;
        AddNode(l2.pHead, m);
    }

    Node* cur = l.pHead; // Initialize a pointer to move freely in the list
    while (cur->pNext != nullptr) {  // Move the poiinter to the last node of the first list
        cur = cur->pNext;
    }
    cur->pNext = l2.pHead; // Connect the last node of the first list to th first node of the second list

    printList(l.pHead);

    deleteList(l.pHead);

    return 0;
}