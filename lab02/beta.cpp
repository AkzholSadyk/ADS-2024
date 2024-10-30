// #include <bits/stdc++.h>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int value){
//         this->data = value;
//         this->next = nullptr;

//     }

// };

// class LinkedList{
//     public:
//     Node* head;
//     Node* tail;
//     int len;

//     LinkedList(){
//         this->head = nullptr;
//         this->tail = nullptr;
//         this->len = 0;
//     }

//     void insert(int data){
//         Node* newElement = new Node(data);
//         if(!head){
//             head = newElement;
//             tail = newElement;
//             return;
//         }
//         else{
//             tail->next = newElement;
//             tail = tail->next;
//         }
        
//     }

//     int NearNum(int k){    
//         Node* current;
//         current = head;
//         int i = 0;
//         int minIndex = 0;
        
//         int distance = abs(head->data - k);
//         while(current){
//             if(abs(current->data - k) < distance){
//                 distance = abs(current->data - k);
//                 minIndex = i;
//             }
//             i++;
//             current = current->next;
//         }
//         return minIndex;
//     }

//     // void print(){
//     //     Node* step = head;
//     //     while(step!=NULL){
//     //         cout << step -> data << ' ';
//     //         step = step->next;
//     //     }
//     // }

// };


// int main(){
//     LinkedList LL;
//     int s; cin >> s;
//     for(int i = 0; i < s; i++){
//         int d; cin >> d;
//         LL.insert(d);
//     }
//     int san; cin >> san;
//     cout << LL.NearNum(san);
//     return 0;
// }
#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) {
        val = x;
        next = NULL;
    }
};

struct ll {
    node* head;
    node* tail;
    int len;
    ll() {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    void add(int x) {
        node* block = new node(x);
        if (head == NULL) {
            head = block;
            tail = block;
        } else {
            tail->next = block;
            tail = tail->next;
        }
        len++;
    }

    int solving(int k) {
        node* arman = head;
        int a = 0;
        int size = 0;

        int distance = abs(head->val - k);
        while (arman) {
            if (abs(arman->val - k) < distance) {
                distance = abs(arman->val - k);
                size = a;
            }
            a++;
            arman = arman->next;
        }

        return size;
    }
};

int main() {
    int x;
    cin >> x;

    ll akzhol;
    for (int i = 0; i < x; ++i) {
        int a;
        cin >> a;
        akzhol.add(a);
    }
    int k;
    cin >> k;

    cout << akzhol.solving(k);
}
