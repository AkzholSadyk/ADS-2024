#include <iostream>

using namespace std;

struct node{
    string val;
    node* next;
    node(string x){
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
        len = 0;
    }
    
    void add(string x){
        int a;
        
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
       

    void solving(int k, int x){    
        node* arman ;
        arman = head;
        int a = 0;
        int size = x;

        while(arman){
            if(k <= a){
                cout << arman->val << " ";
                size--;
            }
            a++;
            arman = arman -> next;
            }
        

        while(size!=0){
            cout << head -> val << " ";
            head = head -> next;
            size--;
            }
        }
    };

int main(){
    int x;cin >> x;
    int k;cin >> k;

    ll akzhol; 
    for(int i =0;i < x; ++i){
        string a; cin >> a;
        akzhol.add(a);
    }

    akzhol.solving(k, x);
}