#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* createnode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// BST INSERT FUNCTION
node* insertBST(node* root, int value) {
    if (root == NULL) {
        return createnode(value);
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    } else {
        cout << "Duplicate value not allowed in BST: " << value << endl;
    }

    return root;
}

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;

    int n, value;
    cout << "How many values you want to insert in BST? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        root = insertBST(root, value);
    }

    cout << "\nInorder Traversal (Sorted Values): ";
    inorder(root);
    cout << endl;

    return 0;
}
