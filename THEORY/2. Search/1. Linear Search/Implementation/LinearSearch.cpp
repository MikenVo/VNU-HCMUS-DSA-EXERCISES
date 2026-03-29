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

// Linked list search
bool ListSearch(int len) {
    // Initialization
    int num;
    int target;
    List l;

    Init(l); // Initialize the linked list, set the pHead to nullptr

    // Input linked list
    cout << "Input the list: ";
    for (int i = 0; i < len; i++) {
        cin >> num;
        AddTail(l, num);
    }

    // Input the target
    cout << "Input your target number: "; cin >> target;

    // Use linear search to find the target number in the linked list
    Node* cur = l.pHead;
    while (cur != nullptr) {  // Continue searching until the pointer 'cur' reaches nullptr
        if (target == cur->data) { // If the target number is found
            deleteList(l); // Delete the list
            return true; // Return true
        }
        cur = cur->pNext;
    }

    // Still delete the list is the target number is not found
    deleteList(l);
    return false; // Return false
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
    // Let the user input the data structure they want to use to apply linear search
    int query;
    cout << "Press 0 to apply linear search to an array, 1 to apply linear search to a linked list: ";
    cin >> query;

    // If the query is not valid, tell the user and exit the program
    if (query != 0 && query != 1) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Input the number of elements
    int len; cout << "Input the number of elements: "; cin >> len;

    // Array linear search
    if (query == 0) {
        if (ArrSearch(len)) {
            cout << "We found the target number!" << endl; // Print this when the element is found
        }
        else {
            cout << "The target number is not available!" << endl; // Print this when the element is not found
        }
    }
    // Linked list linear search
    else if (query == 1) {
        if (ListSearch(len)) {
            cout << "We found the target number!" << endl; // Print this when the element is found
        }
        else {
            cout << "The target number is not available!" << endl; // Print this when the element is not found
        }
    }

    return 0;
}