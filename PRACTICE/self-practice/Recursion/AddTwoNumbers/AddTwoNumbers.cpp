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
    cur->pNext = node;
}

void Init(List &l) {
    l.pHead = nullptr;
}

void deleteList(List &l) {
    Node *cur = l.pHead;
    while (l.pHead != nullptr) {
        l.pHead = l.pHead->pNext;
        delete cur;
        cur = l.pHead;
    }
}

void printlist(Node* pHead) {
    Node* cur = pHead;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->pNext;
    }
    cout << endl;
}

Node* Calculate(Node* list1, Node* list2) {
    const Node* head = list1;
    int sum = 0;
    int add_element = 0;
    int carry = 0;
    Node* cur = list1;
    

    if (list1 == nullptr && list2 == nullptr) {
        return head;
    }
    else {
        sum = (list1->data + list2->data) + carry;
        add_element = sum % 10;
        carry = sum / 10;

        cur->data = add_element;

        if (cur->pNext == nullptr && list2->pNext != nullptr) {
            AddTail(cur, add_element);
        }
    }

    return Calculate(list1->pNext, list2->pNext);
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



    deleteList(l1);
    deleteList(l2);

    return 0;
}