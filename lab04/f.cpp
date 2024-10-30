
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* right;
    Node* left;

    Node(int data) {
        this->value = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    int countTringle = 0;
    int len = 0;
    Node* root;
    Node* tobe;

    BinaryTree() {
        this->root = nullptr;
        this->tobe = nullptr;
    }

    void add(int data) {
        Node* newElement = new Node(data);

        if (!root) {
            root = newElement;
            len++;
            return;
        }

        Node* current = root;

        while (true) {
            if (data < current->value) {
                if (!current->left) {
                    current->left = newElement;
                    len++;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (!current->right) {
                    current->right = newElement;
                    len++;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    // void solving(int b) {
    //     Node* current = root;
    //     bool era = true;
    //     while (era) {
    //         if (b < current->value) {
    //             current = current->left;
    //         } else if (b > current->value) {
    //             current = current->right;
    //         } else if (b == current->value) {
    //             era = false;
    //         }
    //     }
    //     tobe = current; // Set the class member variable
    // }

    int answer(Node* root) {
        if (!root) {
            return 0;
        }
        
        if(root->left and root->right){
            countTringle++;
        }

        int leftway = answer(root->left);
        int rightway = answer(root->right);

        return countTringle;
    }
};

int main() {
    BinaryTree aza;

    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
        int aa;
        cin >> aa;
        aza.add(aa);
    }

    //aza.solving(b);

    cout << aza.answer(aza.root);

    return 0;
}
