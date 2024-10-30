#include <iostream>
#include <vector>
#include <set>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
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
    Node* BSTInsert(Node* root, Node *pt);
    void inorderHelper(Node *root, vector<int> &result);

public:
    RedBlackTree() { root = nullptr; }
    void insert(const int &data);
    vector<int> inorder();
    bool search(int data);
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

Node* RedBlackTree::BSTInsert(Node* root, Node *pt) {
    if (root == nullptr)
        return pt;

    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

void RedBlackTree::insert(const int &data) {
    Node *pt = new Node(data);

    root = BSTInsert(root, pt);

    fixInsert(root, pt);
}

void RedBlackTree::inorderHelper(Node *root, vector<int> &result) {
    if (root == nullptr)
        return;

    inorderHelper(root->left, result);
    result.push_back(root->data);
    inorderHelper(root->right, result);
}

vector<int> RedBlackTree::inorder() {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

bool RedBlackTree::search(int data) {
    Node* current = root;
    while (current != nullptr) {
        if (data == current->data)
            return true;
        else if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    RedBlackTree tree1, tree2;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        tree1.insert(num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        tree2.insert(num);
    }

    vector<int> commonNumbers;
    vector<int> inorder1 = tree1.inorder();

    for (int num : inorder1) {
        if (tree2.search(num)) {
            commonNumbers.push_back(num);
        }
    }

    for (int num : commonNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
