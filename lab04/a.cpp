#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* right;
    Node* left;

    Node(int data){
        this->value=data;
        this->left= nullptr;
        this->right=nullptr;
    }
};

class BinaryTree{
    public:
    int len=0;
    Node* root;

    BinaryTree(){
        this->root=nullptr;
    }

    void add(int data){
        Node* newElement = new Node(data);

        if(!root){
            root = newElement;
            len++;
            return;
        }

        Node* current = root;

        while(true){
            if (data < current->value){
                if(!current->left){
                    current->left= newElement;
                    len++;
                    break;
                }
                else{
                    current = current->left;
                }
            }
            else{
                if(!current->right){
                    current->right= newElement;
                    len++;
                    break;
                }
                else{
                    current= current->right;
                }
            }
        }
    }

    void path(string path){
        Node* current = root;

        for(int i=0;i<path.size();i++){
            char ako = path[i];
            if(ako =='L'){
                if(!current->left){
                    cout << "NO" << endl;
                    return;
                }
                else{
                    current = current->left;
                }
            }
            else if(ako =='R'){
                if(!current->right){
                    cout << "NO" << endl;
                    return;
                }
                else{
                    current = current-> right;
                }
            }
        }
        cout << "YES" << endl;
    }
};


int main(){

    BinaryTree aza;

    int a;cin>> a;
    int b;cin>> b;
    
    for(int i=0;i<a;i++){
        int aa;cin >> aa;
        aza.add(aa);
    }
    for(int i=0;i<b;i++){
        string cc;cin >> cc;
        aza.path(cc);
    }

    return 0;
}