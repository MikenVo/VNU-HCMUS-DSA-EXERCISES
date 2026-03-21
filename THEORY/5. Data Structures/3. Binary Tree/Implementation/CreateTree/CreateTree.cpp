#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

struct List {
    Node* pRoot;
};

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->pLeft = nullptr;
    newnode->pRight = nullptr;
    return newnode;
}

void AddNode(Node* &pRoot, int data) {
    if (pRoot == nullptr) {
        Node* node = CreateNode(data);
        pRoot = node;
        return;
    }

    if (data < pRoot->data) {
        AddNode(pRoot->pLeft, data);
    }
    else if (data > pRoot->data) {
        AddNode(pRoot->pRight, data);
    }
}

// Search the target element in the tree
// - Check if the target is larger or smaller that the current node
// - - If larger, move right
// - - If smaller, move left

// Time complexity:
// - Best case: The value is on the root node (O(1))
// - Worst case: The tree is either increasing or decreasing (O(n))
bool BinaryTreeSearch(Node* pRoot, int target) {
    if (pRoot == nullptr) { // We encounter the leaf node, but cannot find the element
        return false; // Set false
    }

    if (target < pRoot->data) { // The target is smaller that the current node's data
        return BinaryTreeSearch(pRoot->pLeft, target); // We move left
    }
    else if (target > pRoot->data) { // The target is larger that the current node's data
        return BinaryTreeSearch(pRoot->pRight, target); // We move right
    }
    else { // If we reach this part, it is guaranteed that we have found the target
        return true; // Set true
    }
}

// Find the largest element on the left branch of the tree
// - The largest number of the left branch is the rightmost value
void predecessor(Node* pRoot) {
    Node* cur = pRoot->pLeft; // Set a pointer pointing to the first left node
    while (cur->pRight != nullptr) { // Move right until reach the rightmost leaf node
        cur = cur->pRight;
    }
    cout << cur->data << endl; // Print out the rightmost value
}

// Find the smallest element on the right branch of the tree
// - The smallest number of the right branch is the leftmost value
void successor(Node *pRoot) {
    Node *cur = pRoot->pRight; // Set a pointer pointing to the first right node
    while (cur->pLeft != nullptr) { // Move left until reach the leftmost leaf node
        cur = cur->pLeft;
    }
    cout << cur->data << endl; // Print out the leftmost value
}

void Init(List &l) {
    l.pRoot = nullptr;
}

int main() {
    List l;
    Init(l);

    // Insert nodes
    AddNode(l.pRoot, 10);
    AddNode(l.pRoot, 5);
    AddNode(l.pRoot, 14);

    // Binary tree search
    cout << BinaryTreeSearch(l.pRoot, 5) << endl;

    // Find the largest element on the left branch and smallest on the right branch
    predecessor(l.pRoot);
    successor(l.pRoot);

    return 0;
}