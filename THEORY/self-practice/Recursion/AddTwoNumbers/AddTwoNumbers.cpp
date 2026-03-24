#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
};

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->pNext = nullptr;
    return newnode;
}

void AddTail(Node* &pHead, int data) {
    Node* node = CreateNode(data);
    
    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    Node* cur = pHead;
    while (cur->pNext != nullptr) {
        cur = cur->pNext;
    }
    cur = node;
}

void Init(List &l) {
    l.pHead = nullptr;
}

void deleteList(Node *&pHead) {
    Node *cur = pHead;
    while (pHead != nullptr) {
        pHead = pHead->pNext;
        delete cur;
        cur = pHead;
    }
}

void printlist(Node* pHead) {
    Node* cur = pHead;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->pNext;
    }
    cur = nullptr;
}

void Calculate(Node* &list1, Node* &list2) {
    int sum = 0;
    int add_element = 0;
    int carry = 0;
    List l3;
    l3.pHead = nullptr;

    while (list1 != nullptr || list2 != nullptr) {
        sum = (list1->data + list2->data) + carry;
        add_element = sum % 10;
        carry = sum / 10;

        AddTail(l3.pHead, add_element);
    }

    printlist(l3.pHead);
    deleteList(l3.pHead);
}

int main() {
    List l1;
    List l2;
    int m;
    int len1;
    int len2;
    Node *list1;
    Node *list2;

    Init(l1);
    Init(l2);

    cin >> len1;
    for (int i = 0; i < len1; i++) {
        cin >> m;
        AddTail(l1.pHead, m);
    }

    cin >> len2;
    for (int i = 0; i < len2; i++) {
        cin >> m;
        AddTail(l2.pHead, m);
    }

    list1 = l1.pHead;
    list2 = l2.pHead;
    Calculate(list1, list2);

    deleteList(l1.pHead);
    deleteList(l2.pHead);

    return 0;
}