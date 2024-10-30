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
    int len;
    ll(){
        head = NULL;
        len = 0;
    }
    
    void add(int x){
        int a;
        
        node* block = new node(x);
        if(head == NULL){
            head = block;
            len++;
            }
        else{
            node* step = head;
            while(step -> next != NULL){
                step = step -> next;
                }
            step ->next=block;
            len++;
            }
            }
       

    void print(){
        node* arman  = head;
        int a = 0;
        while(arman!=NULL){
        if(a%2==0){
                cout << arman->val << " ";
            }
            a++;
            arman = arman -> next;
            }
        }
    };

int main(){
    int x;
    cin >> x;

    ll akzhol; 
    for(int i =0;i < x; ++i){
        int num; cin >> num;
        akzhol.add(num);
    }

    akzhol.print();
}