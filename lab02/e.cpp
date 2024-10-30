#include <iostream>

using namespace std;

struct node{
    string val;
    node* next;
    node* back;
    node(string x){
        val = x;
        next = NULL;
        back = NULL;
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
    
    void add(string x){
        node*ako;
        ako = head;
        
        node* block = new node(x);
        if(head == NULL){
            head = block;
            tail = block;
            len++;
        } else{
            if(head->val == x){
                return;
            }
            else{
                head->back = block;
                head = block;
                head->next = ako;
                len++;
            }
            }
        
        }
       

    void solving(){    
        node* arman;
        arman = head;
        cout<< "All in all: " << len << endl <<"Students: "<< endl;
        while(arman){
            cout<< arman->val<< endl;
            arman = arman->next;
        }
    }
};


int main(){
    int x;cin >> x;
    ll akzhol; 
    for(int i =0;i < x; ++i){
        string a; cin >> a;
        akzhol.add(a);
    }

    akzhol.solving();
}