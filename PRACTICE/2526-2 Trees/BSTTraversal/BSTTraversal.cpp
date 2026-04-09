#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

struct List {
    Node* root;
};

void Init(List& l) {
    l.root = nullptr;
}

Node* CreateNode(int data) {
    Node* newnode = new Node();
    newnode->val = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

void addNode(Node* &root, int x) {
    if (root == nullptr) {
        Node* node = CreateNode(x);
        root = node;
        return;
    }

    if (x > root->val) {
        return addNode(root->right, x);
    }
    else if (x < root->val) {
        return addNode(root->left, x);
    }
    Node* node = CreateNode(x);
    root = node;
}

bool existsinBST(Node* root, int x) {
    while (root != nullptr) {
        if (x == root->val) {
            return true;
        }
        else if (x > root->val) {
            return existsinBST(root->right, x);
        }
        else {
            return existsinBST(root->left, x);
        }
    }
    return false;
}

// Traversals

// In-order (LNR)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Pre-order (NLR)
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order (LRN)
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List l;
    Init(l);

    int command;
    while (cin >> command) {
        if (command == 1) {
            int addnum = 0;
            cin >> addnum;
            if (!existsinBST(l.root, addnum)) {
                addNode(l.root, addnum);
            }
        }
        else if (command == 2) {
            char* type = new char[4]();
            cin >> type;

            if (strcmp(type, "LNR") == 0) {
                inorder(l.root);
            }
            else if (strcmp(type, "NLR") == 0) {
                preorder(l.root);
            }
            else if (strcmp(type, "LRN") == 0) {
                postorder(l.root);
            }
            cout << '\n';

            delete[] type;
        }
        else if (command == 3) {
            int addnum = 0;
            cin >> addnum;
            
            if (existsinBST(l.root, addnum)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}