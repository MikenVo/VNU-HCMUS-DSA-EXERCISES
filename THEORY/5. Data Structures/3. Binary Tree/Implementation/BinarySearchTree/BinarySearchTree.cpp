#include <iostream>
using namespace std;

// Tree Properties
struct Node {
    int data; // Store the value of the node
    Node* pLeft; // Points to the left node
    Node* pRight; // Points to the right node
};

struct List {
    Node* pRoot;
};

// ---------- Operation ----------
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

void Deletion(Node* &pRoot) {
    // There are two cases of deletion
    // 1. The node we want to delete is a leaf node (has no child) -> Delete right away
    // 2. The node we want to delete is not a leaf node (has 1 or 2 children) -> Move the node to the leaf node and delete

    // 1. The node we want to delete is a leaf node
    
}

void Init(List &l) {
    l.pRoot = nullptr;
}

// ---------- Traversal ----------
// Problem: Traversal the tree in Root - Left - Right order
void preorder(Node* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    cout << pRoot->data << " "; // Print the value of the root first (Root)
    preorder(pRoot->pLeft); // Move to the left and print all the values on the left (Left)
    preorder(pRoot->pRight); // Move to the right and print all the values on the right (Right)
}

// Problem: Traversal the tree in Left - Root - Right order
void inorder(Node* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    inorder(pRoot->pLeft); // Move to the left and print all the values on the left (Left)
    cout << pRoot->data << " "; // Print the value of the root (Root)
    inorder(pRoot->pRight); // Move to the right and print all the values on the right (Right)
}

// Problem: Traversal the tree in Left - Right - Root order
void postorder(Node* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    postorder(pRoot->pLeft); // Move to the left and print all the values on the left (Left)
    postorder(pRoot->pRight); // Move to the right and print all the values on the right (Right)
    cout << pRoot->data << " "; // Print the value of the root (Root)
}

// ----------  Finding  ---------- 
// Problem: Check if the element is in the tree

// Search the target element in the tree
// - Check if the target is larger or smaller that the current node
// - - If larger, move right
// - - If smaller, move left
// - - If we find the target, return true, else, return false

// Time complexity:
// - Best case: The value is on the root node (O(1))
// - Worst case: The tree is either increasing or decreasing (Linked List) (O(n))
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

// Problem: Find the largest element on the left branch of the tree (Predecessor)
// - The largest number of the left branch is the rightmost value
void predecessor(Node* pRoot) {
    // Because we are finding the largest number of the left branch, we need to set the pointer to the first left node
    Node* cur = pRoot->pLeft; // Set a pointer pointing to the first left node
    while (cur->pRight != nullptr) { // Move right until reach the rightmost leaf node because all the largest values will on the right
        cur = cur->pRight;
    }
    cout << "Predecessor: " << cur->data << endl; // Print out the rightmost value
}

// Problem: Find the smallest element on the right branch of the tree (Successor)
// - The smallest number of the right branch is the leftmost value
void successor(Node *pRoot) {
    // Because we are finding the smallest number of the right branch, we need to set the pointer to first right node
    Node *cur = pRoot->pRight; // Set a pointer pointing to the first right node
    while (cur->pLeft != nullptr) { // Move left until reach the leftmost leaf node
        cur = cur->pLeft;
    }
    cout << "Successor: " << cur->data << endl; // Print out the leftmost value
}

int main() {
    List l;
    Init(l);

    // Insert nodes
    int n; cout << "Type the number of nodes: "; cin >> n; // Let the user define the number of nodes
    int num; // Store the value for the current node
    for (int i = 0; i < n; i++) {
        cin >> num;
        AddNode(l.pRoot, num);
    }

    // ----------------- Traversal -----------------
    cout << "Preorder (Root -> Left -> Right): ";
    preorder(l.pRoot);
    cout << endl;

    cout << "Inorder (Left -> Root -> Right): ";
    inorder(l.pRoot);
    cout << endl;

    cout << "Postorder (Left -> Right -> Root): ";
    postorder(l.pRoot);
    cout << endl;

    // -----------------  Finding  -----------------
    // Search an element
    int target; cout << "Type the target number: "; cin >> target;
    if (BinaryTreeSearch(l.pRoot, target)) {
        cout << "FOUND!" << endl;
    }
    else {
        cout << "NOT FOUND!" << endl;
    }

    // Find the largest element on the left branch and smallest on the right branch
    predecessor(l.pRoot);
    successor(l.pRoot);

    return 0;
}