#include <iostream>
using namespace std;

// Tree Properties
struct Node {
    int data; // Store the value of the node
    Node* pLeft; // Points to the left node
    Node* pRight; // Points to the right node
    int height; // Store the height of a node
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
    newnode->height = 1;
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
    // LRN deletion
    if (pRoot == nullptr) {
        return;
    }

    Deletion(pRoot->left);
    Deletion(pRoot->right);
    delete pRoot;
    pRoot = nullptr;
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
bool Search(Node* pRoot, int target) {
    if (pRoot == nullptr) { // We encounter the leaf node, but cannot find the element
        return false; // Set false
    }

    if (target < pRoot->data) { // The target is smaller that the current node's data
        return Search(pRoot->pLeft, target); // We move left
    }
    else if (target > pRoot->data) { // The target is larger that the current node's data
        return Search(pRoot->pRight, target); // We move right
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

// ----------  Rotation ----------
// We need to extract the height of the specific node to use for balance calculation
int height(Node* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }
    else {
        return pRoot->height;
    }
}

int balance(Node* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }
    else {
        // The reason we only need to extract the height of the left and right nodes
        // - The heights of those nodes are updated right away when a new child joins the family
        return height(pRoot->left) - height(pRoot->right);
    }
}

void LL (Node* &pRoot) {
    Node* newRoot = pRoot;
    Node* newRootRight = newRoot->right;

    
}

void rotation(Node* &pRoot) {
    int balancepoint = balance(pRoot);


}

// ----------  Deletion ----------
void targetDeletion(Node* &pRoot, int target) {
    // There are 2 cases for "Target Deletion" in tree:
    // 1. The target node has no child -> Delete
    // 2. The target node has 1 or 2 children 
    // -> Copy the target node with the successor to maintain the BST 
    // -> Find the successor explicitly on the right sub branch
    // -> Delete duplicated successor

    // Step 1: Find the target
    if (target > pRoot->data) {
        targetDeletion(pRoot->right, target);
    }
    else if (target < pRoot->data) {
        targetDeletion(pRoot->left, target);
    }
    else { // Found the target!
        // Case 1: No child
        if (pRoot->left == nullptr && pRoot->right == nullptr) { // Check if the target node is a leaf node
            delete pRoot;
            pRoot = nullptr;
        }
        // Case 2: Has children (1 or 2)
        else {
            // Case 2.1: Has 1 child
            if (pRoot->left == nullptr) { // No left child, only right child
                Node* temp = pRoot->right; // We take whole right branch
                delete pRoot; // Delete the target node
                pRoot = temp; // Relink the whole right branch to the main branch
            }
            else if (pRoot->right == nullptr) { // No right child, only left child
                Node* temp = pRoot->left; // We take whole left branch
                delete pRoot;
                pRoot = temp;
            }
            // Case 2.2: Has 2 children
            else {
                // Find the successor
                Node* temp = pRoot->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }

                pRoot->data = temp->data; // Copy the successor value to the root value
                targetDeletion(pRoot->right, temp->data); // Find the successor and delete only in the right branch
            }
        }
    }
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
    if (Search(l.pRoot, target)) {
        cout << "FOUND!" << endl;
    }
    else {
        cout << "NOT FOUND!" << endl;
    }

    // Find the largest element on the left branch and smallest on the right branch
    predecessor(l.pRoot);
    successor(l.pRoot);

    Deletion(l.pRoot);

    return 0;
}