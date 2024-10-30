#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = NULL;
    }
};

struct ll{
    node* head;
    node* tail;
    int len;
    ll(){
        head = NULL;
        tail = NULL;
        len = 0;
    }
    
    void add(int x){
        node* block = new node(x);
        if(head == NULL){
            head = block;
            tail = block;
        }
        else{
            tail->next = block;
            tail = tail->next;
            
        }
        len++;
    }
       

    int solving(int k){    
        node* arman = head;
        int a = 0;
        int size = 0;

        int distance = abs(head->val - k);
        while(arman){
            if(abs(head->val -k) < distance){
                distance = abs(arman->val - k);
                size = a;
            }
            a++;
            arman = arman -> next;
        }

        return size;
    }
};

int main(){
    int x;cin >> x;

   ll akzhol; 
    for(int i =0;i < x; ++i){
        int a; cin >> a;
        akzhol.add(a);
    }
    int k;cin >> k;

    cout << akzhol.solving(k);
}