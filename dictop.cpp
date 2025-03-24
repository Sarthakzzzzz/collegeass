#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* createNode(string key, string value) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, string key, string value) {
    if (!root) return createNode(key, value);

    if (key < root->key) root->left = insert(root->left, key, value);
    else if (key > root->key) root->right = insert(root->right, key, value);
    else {
        root->value = value; // Update value
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Balancing the tree
    if (balance > 1 && key < root->left->key) return rightRotate(root);
    if (balance < -1 && key > root->right->key) return leftRotate(root);
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrderTraversal(Node* root, bool ascending = true) {
    if (root) {
        if (ascending) {
            inOrderTraversal(root->left, ascending);
            cout << root->key << ": " << root->value << endl;
            inOrderTraversal(root->right, ascending);
        } else {
            inOrderTraversal(root->right, ascending);
            cout << root->key << ": " << root->value << endl;
            inOrderTraversal(root->left, ascending);
        }
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, "cat", "a small domesticated animal");
    root = insert(root, "dog", "a domesticated canine");
    root = insert(root, "apple", "a fruit");

    cout << "Ascending order:" << endl;
    inOrderTraversal(root, true);

    cout << "Descending order:" << endl;
    inOrderTraversal(root, false);

    return 0;
}

