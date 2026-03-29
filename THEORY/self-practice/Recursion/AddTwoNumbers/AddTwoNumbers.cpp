#include <iostream>
using namespace std;

struct Node {
    int data = 0;
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

Node* Calculate(Node* List1, Node* List2) {
    int sum = 0, add_element = 0, carry = 0;
    Node* head = List1;
    
    // 2 - 4 - 3
    // 5 - 6 - 4
    // 243 + 564 = 807
    // 7 - 0 - 8

    while (List1 != nullptr || List2 != nullptr) {
        if (List1 == nullptr && List2 != nullptr) {
            sum = (List2->data) + carry;
            add_element = sum % 10;
            carry = sum / 10;

            AddTail(head, add_element);
        }
        else if (List1 != nullptr && List2 == nullptr) {
            sum = (List1->data) + carry;
            add_element = sum % 10;
            carry = sum / 10;

            List1->data = add_element;
        }
        else {
            sum = (List1->data + List2->data) + carry;
            add_element = sum % 10;
            carry = sum / 10;

            List1->data = add_element;
        }

        if (List1 != nullptr) {
            List1 = List1->pNext;
        }

        if (List2 != nullptr) {
            List2 = List2->pNext;
        }
    }

    if (carry != 0) {
        AddTail(head, carry);
    }

    return head;
}

int main() {
    List l1;
    List l2;
    int m;
    int len1;
    int len2;

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

    printlist(Calculate(l1.pHead, l2.pHead));

    deleteList(l1.pHead);
    deleteList(l2.pHead);

    return 0;
}