// Problem: Given two linked lists. Merge them into a linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->pNext = nullptr;

    return newnode;
}

void AddNode(Node* pHead, int data) {
    Node* node = CreateNode(data);
    Node* temp = pHead;

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
}

int main() {

}