// Problem:
// Your program should prompt the user to choose one of the following three operations :
// 1. Insertion (INSERT): Add a new name to the registry. If the name already exists, notify the user that duplicates are not allowed.
// 2. Search (SEARCH): Check if a specific name exists in the registry. Output "FOUND" if it is found or "NOT FOUND" if it is not found.
// 3. Deletion (DELETE): Remove a name from the registry.
// 4. Print (PRINT): Print all the element one by one.
// 5. Exit (EXIT): Exit the program

// Constraints: Address collisions using Open Addressing.

#include <iostream>
#include <cstring>
using namespace std;

int hashfunction(char *target, int MAX_NUM, int array_size) {
    // Hash function:
    // 1. Add every digit in the phone number
    // 2. Take modulo array_size

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < MAX_NUM - 1; i++) {
        sum += target[i] - '0';
    }

    // Calculate the key (Take the sum and modulo 10)
    int key = sum % array_size;
    return key;
}

bool search(char **hashtable, char *target, int MAX_NUM, int array_size) {
    int key = hashfunction(target, MAX_NUM, array_size); // Get the key of the phone number

    // Check at the key-th position. If there is a collision, we increase key by 1
    while (hashtable[key][0] != '\0' && key < array_size) {
        if (strcmp(hashtable[key], target) == 0) { // If the phone number at the key-th position is the same as the target number
            return true; // Return true because we have found the number
        }
        key++; // If the phone number is not the same, we increase key by 1
    }
    return false; // If we find all the keys but no such number is available, we return false
}

void insertion(char **hashtable, char *target, int MAX_NUM, int array_size) {
    bool noslot = false;
    int outkey = 0;
    if (!search(hashtable, target, MAX_NUM, array_size)) { // Add the element if and only if it is not available in the hash table
        int key = hashfunction(target, MAX_NUM, array_size);
        outkey = key;
        // Check collision
        while (hashtable[key][0] != '\0') {
            key++; // If there is a collision, increase the key
            if (key >= array_size) { // If there is no available slot to assign, quit the program
                cout << "OUT OF HASH TABLE" << endl;
                noslot = true;
                break;
            }
        }

        if (noslot) { // If the other half of the hash table runs out of slots, we get back to the start of hash table to search for a slot.
            key = 0;
            while (hashtable[key][0] != '\0') {
                key++;
                if (key >= outkey) {
                    cout << "OUT OF HASH TABLE" << endl;
                    return;
                }
            }
        }

        // Assign the phone number into the memory cell
        strcpy(hashtable[key], target);
    }
}

void deletion(char **hashtable, char *target, int MAX_NUM, int array_size) {
    if (search(hashtable, target, MAX_NUM, array_size)) { // Check if the element is available in the hash table first
        int key = hashfunction(target, MAX_NUM, array_size); // Get the key of the phone number

        while (hashtable[key][0] != '\0' && key < array_size) { // Iterate through the hash table in case there was a collision
            if (strcmp(hashtable[key], target) == 0) { // Check if the phone number at the key-th position is the same as our target
                for (int i = 0; i < MAX_NUM; i++) { // Delete the phone number
                    hashtable[key][i] = '\0';
                }
                return;
            }
            key++;
        }
    }
    else {
        cout << "NOT FOUND" << endl;
    }
}

int main() {
    char *operation = new char[7]();
    int n;
    cout << "Type the size of the hash table: ";
    cin >> n;
    int MAX_NUM = 11;
    char **hashtable = new char *[n]();
    for (int i = 0; i < n; i++) {
        hashtable[i] = new char[MAX_NUM]();
    }

    // The user enters a phone number into a character array.
    // Take each element in the phone number (converts to int), add them together, and modulo the size of the array.
    // If there is a collision, move down one memory cell. If there is no available memory cell, annouce to the user, and quit the program.

    while (true) { // Infinite loop let the user enter as many operations as they want
        // Input
        cout << "Operations: " << endl;
        cout << "1. 'INSERT': Insert an element into the hash table" << endl;
        cout << "2. 'SEARCH': Search an element in the hash table" << endl;
        cout << "3. 'DELETE': Delete an element in the hash table" << endl;
        cout << "4. 'PRINT': Print every element in the hash table" << endl;
        cout << "5. 'EXIT': Exit the program" << endl;
        cout << "Enter your operation: ";
        cin >> operation;

        char *phone_num = new char[MAX_NUM]; // Store the phone number

        if (strcmp(operation, "INSERT") == 0) { // INSERT OPERATION
            cout << "Enter the phone number: ";
            cin >> phone_num; // Enter the phone number
            insertion(hashtable, phone_num, MAX_NUM, n);
            delete[] phone_num; // Deallocation
        }
        else if (strcmp(operation, "SEARCH") == 0) { // SEARCH OPERATION
            cout << "Enter the phone number: ";
            cin >> phone_num; // Enter the phone number
            if (search(hashtable, phone_num, MAX_NUM, n)) { // If it is found, print out "FOUND"
                cout << "FOUND" << endl;
            }
            else { // If it is not found, print out "NOT FOUND"
                cout << "NOT FOUND" << endl;
            }
        }
        else if (strcmp(operation, "DELETE") == 0) { // DELETE OPERATION
            cout << "Enter the phone number: ";
            cin >> phone_num; // Enter the phone number
            deletion(hashtable, phone_num, MAX_NUM, n);
        }
        else if (strcmp(operation, "PRINT") == 0) { // PRINT OPERATION
            for (int i = 0; i < n; i++) {
                cout << i + 1 << ". " << hashtable[i] << endl; // Print the phone number one by one
            }
        }
        else if (strcmp(operation, "EXIT") == 0) { // EXIT OPERATION
            cout << "END OF SESSION" << endl;
            return 0;
        }
        else { // HANDLE INVALID COMMANDS
            cout << "INVALID COMMAND" << endl;
            return 1;
        }
    }

    // Deallocation
    delete[] operation;
    for (int i = 0; i < n; i++) {
        delete[] hashtable[i];
    }
    delete[] hashtable;

    return 0;
}