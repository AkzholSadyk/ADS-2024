#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->value) {
            node->left = insertRec(node->left, val);
        } else if (val > node->value) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    int diameter() {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(Node* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << tree.diameter()+1 << endl;

    return 0;
}
