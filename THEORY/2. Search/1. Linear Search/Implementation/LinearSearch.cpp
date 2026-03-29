#include <iostream>
using namespace std;

// Linked List search
struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
};

void Init(List &l) {
    l.pHead = nullptr;
}

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->pNext = nullptr;
    return newnode;
}

void AddTail(List &l, int data) {
    Node* node = CreateNode(data);

    if (l.pHead == nullptr) {
        l.pHead = node;
        return;
    }

    Node* cur = l.pHead;
    while (cur->pNext != nullptr) {
        cur = cur->pNext;
    }
    cur->pNext = node;
}

void deleteList(List &l) {
    Node* cur = l.pHead;
    
    while (l.pHead != nullptr) {
        l.pHead = l.pHead->pNext;
        delete cur;
        cur = l.pHead;
    }

    l.pHead = nullptr;
    cur = nullptr;
}

bool ListSearch(int len) {
    int num;
    int target;
    List l;

    Init(l);

    // Input linked list
    cout << "Input the list: ";
    for (int i = 0; i < len; i++) {
        cin >> num;
        AddTail(l, num);
    }

    cout << "Input your target number: "; cin >> target;

    Node* cur = l.pHead;
    while (cur != nullptr) {
        if (target == cur->data) {
            deleteList(l);
            return true;
        }
        cur = cur->pNext;
    }

    deleteList(l);
    return false;
}

// Array search
bool ArrSearch(int len) {
    // Initialization
    int *arr = new int[len];
    int target;

    // Input the array
    cout << "Input the array: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    // Input the target number
    cout << "Input your target number: "; cin >> target;

    // Use linear search to find the target number in the array
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            return true; // return true if it is found
        }
    }
    return false; // return false if it is not found
}

int main() {
    int query;
    cout << "Press 0 to apply linear search to an array, 1 to apply linear search to a linked list: ";
    cin >> query;

    if (query != 0 && query != 1) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Input the number of elements
    int len; cout << "Input the number of elements: "; cin >> len;

    if (query == 0) {
        if (ArrSearch(len)) {
            cout << "We found the target number!" << endl;
        }
        else {
            cout << "The target number is not available!" << endl;
        }
    }
    else if (query == 1) {
        if (ListSearch(len)) {
            cout << "We found the target number!" << endl;
        }
        else {
            cout << "The target number is not available!" << endl;
        }
    }

    return 0;
}