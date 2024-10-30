#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    string data;
    int length;
    bool color;
    Node *left, *right, *parent;

    Node(string data) {
        this->data = data;
        this->length = data.length();
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixInsert(Node *&, Node *&);
    void inorderHelper(Node *root, vector<string> &result);

public:
    RedBlackTree() { root = nullptr; }
    void insert(const string &data);
    vector<string> inorder();
};

void RedBlackTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::fixInsert(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node *uncle_pt = grand_parent_pt->left;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::insert(const string &data) {
    Node *pt = new Node(data);

    root = BSTInsert(root, pt);

    fixInsert(root, pt);
}

Node* BSTInsert(Node* root, Node *pt) {
    if (root == nullptr)
        return pt;

    if (pt->length < root->length) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->length > root->length) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    } else {
        // Maintain original order for strings of the same length
        if (pt->data < root->data) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        } else {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }
    }

    return root;
}

void RedBlackTree::inorderHelper(Node *root, vector<string> &result) {
    if (root == nullptr)
        return;

    inorderHelper(root->left, result);
    result.push_back(root->data);
    inorderHelper(root->right, result);
}

vector<string> RedBlackTree::inorder() {
    vector<string> result;
    inorderHelper(root, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string word;
        RedBlackTree tree;

        while (iss >> word) {
            tree.insert(word);
        }

        vector<string> sortedStrings = tree.inorder();
        for (const string &str : sortedStrings) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
