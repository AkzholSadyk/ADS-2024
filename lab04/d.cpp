
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
    deque<int> ero;
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
            ero.push_back(root->value);
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

    int answer(Node* root) {
         if (!root) {
            return 0 ;
        }
        
        
        Node* sol = root->left;
        Node* on = root->right;
        
    
        if(root->left and root->right){
            ero.push_back(sol->value + on->value);    
        }

        if(root->left and !root->right){
            ero.push_back(sol->value);
        }

        if(!root->left and root->right){
            ero.push_back(on->value);
        }

        int leftway = answer(root->left);
        int rightway = answer(root->right);


        return countTringle;
    }

    void sout(){
        cout<< ero.size() << endl;

        for(int i=0;i<ero.size();i++){
            cout << ero[i] << " ";
        }
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

    aza.answer(aza.root);
    aza.sout();

    return 0;
}
