// Problem:
// Your program should prompt the user to choose one of the following three operations :
// 1. Insertion (INSERT): Add a new name to the registry. If the name already exists, notify the user that duplicates are not allowed.
// 2. Search (SEARCH): Check if a specific name exists in the registry. Output "FOUND" if it is found or "NOT FOUND" if it is not found.
// 3. Deletion (DELETE): Remove a name from the registry.
// 4. Print (PRINT): Print all the element one by one.
// 5. Exit (EXIT): Exit the program

// Constraints: Address collisions using Chaining.

#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char* data = new char[11];
    Node* next;

    ~Node() {
        delete[] data;
    }
};

Node* CreateNode(char* data) {
    Node* newnode = new Node();
    strcpy(newnode->data, data);
    newnode->next = nullptr;
    return newnode;
}

void AddTail(Node* &head, char* data) {
    Node* node = CreateNode(data);
    
    if (head == nullptr) {
        head = node;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = node;
}

int hashfunction(char* phone_number, int MAX_VALUE, int array_size) {
    int sum = 0;

    // Hash function:
    // - Sum up every digit in the phone number
    // - Modulo the total with the size of the array

    // Calculate the sum of the phone number
    for (int i = 0; i < MAX_VALUE - 1; i++) {
        sum += phone_number[i] - '0';
    }

    // Modulo the total with the size of the array to get the key
    int key = sum % array_size;
    return key;
}

Node* search(Node** hashtable, char* phone_number, int MAX_VALUE, int array_size) {
    int key = hashfunction(phone_number, MAX_VALUE, array_size);
    Node* cur = hashtable[key];

    if (hashtable[key] == nullptr) {
        return nullptr;
    }
    else {
        while (cur != nullptr) {
            if (strcmp(cur->data, phone_number) == 0) {
                return cur;
            }
            cur = cur->next;
        }
    }
    return nullptr;
}

void insert(Node** hashtable, char* phone_number, int MAX_VALUE, int array_size) {
    // We get the key corresponding to the phone number
    // At the key-th position, we initialize a Linked List

    int key = hashfunction(phone_number, MAX_VALUE, array_size); // Get the key corresponding to the phone number
    if (key > array_size) {
        key = 0;
        return;
    }

    if (search(hashtable, phone_number, MAX_VALUE, array_size) == nullptr) { 
        // We simply add the element into the key-th position. If there is a collision, it will lengthen the Linked List
        AddTail(hashtable[key], phone_number);
    }
}

void deletion(Node** hashtable, char* phone_number, int MAX_VALUE, int array_size) {
    Node* target = search(hashtable, phone_number, MAX_VALUE, array_size);
    int key = hashfunction(phone_number, MAX_VALUE, array_size);

    // Three cases: The head of the list, the middle of the list, the end of the list
    if (target == nullptr) {
        cout << "NOT FOUND" << endl;
        return;
    }

    if (target == hashtable[key]) {
        Node* cur = hashtable[key];
        hashtable[key] = hashtable[key]->next;
        delete cur;
    }
    else {
        Node* cur = hashtable[key];
        while (cur->next != target) {
            cur = cur->next;
        }

        cur->next = target->next;
        delete target;
        target = nullptr;
    }
}

void deletion2(Node* &head) {
    if (head == nullptr) {
        return;
    }

    Node* cur = head;
    while (head != nullptr) {
        head = head->next;
        delete cur;
        cur = head;
    }
}

void print(Node **hashtable, int MAX_VALUE, int array_size) {
    for (int i = 0; i < array_size; i++) {
        Node *cur = hashtable[i];
        cout << i + 1 << ". ";
        while (cur != nullptr) {
            cout << cur->data << " -> "; // Shows the chain clearly
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
}

int main () {
    int array_size; int MAX_VALUE = 11;
    cout << "Enter the size of the array (the number of elements in the array): "; cin >> array_size; // Enter the size of the hash table

    // Initialize a hash table
    Node** hashtable = new Node*[array_size]();
    for (int i = 0; i < array_size; i++) {
        hashtable[i] = nullptr;
    }

    // Initialize a character array to hold the phone number
    char *phone_number = new char[MAX_VALUE]();

    while (true) {
        char* operation = new char[7]();
        cout << "1. INSERT: Insert a new element into the hash table." << endl;
        cout << "2. SEARCH: Search an element in the hash table." << endl;
        cout << "3. DELETE: Delete an element in the hash table." << endl;
        cout << "4. PRINT: Print all the elements one by one." << endl;
        cout << "5. EXIT: Exit the program." << endl;
        cout << "Enter an operation from one of these above: "; cin >> operation; // Enter the operation

        if (strcmp(operation, "INSERT") == 0) { // Insert operation
            cout << "Enter the phone number: "; cin >> phone_number;
            insert(hashtable, phone_number, MAX_VALUE, array_size);
        }
        else if (strcmp(operation, "SEARCH") == 0) { // SEARCH operation
            cout << "Enter the phone number: "; cin >> phone_number;
            if (search(hashtable, phone_number, MAX_VALUE, array_size) != nullptr) {
                cout << "FOUND" << endl;
            }
            else {
                cout << "NOT FOUND" << endl;
            }
        }
        else if (strcmp(operation, "DELETE") == 0) { // DELETE operation
            cout << "Enter the phone number: "; cin >> phone_number;
            deletion(hashtable, phone_number, MAX_VALUE, array_size);
        }
        else if (strcmp(operation, "PRINT") == 0) { // PRINT operation
            print(hashtable, MAX_VALUE, array_size);
        }
        else if (strcmp(operation, "EXIT") == 0) { // EXIT operation
            cout << "EXIT THE PROGRAM" << endl;
            break;
        }
        else {
            cout << "INVALID OPERATION" << endl;
        }

        delete[] operation;
    }

    delete[] phone_number;
    for (int i = 0; i < array_size; i++) {
        deletion2(hashtable[i]);
    }
    delete[] hashtable;
    return 0;
}