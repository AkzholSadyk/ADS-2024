

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node* back;
    node(int x){
        val = x;
        next = NULL;
        back = NULL;
    }
};

struct ll{
    node* head=NULL;
    node* tail=NULL;
    int len=0;
    void add(int x){
        node* element = new node(x);
        if(head == NULL){
            head = element;
            tail = element;
        }
        else{
            tail->next = element;
            tail = tail->next;
        }
        len++;
    }
    
    void solvingModa(int b,int c){
        node* current = head;
        int ee=0;
        while(current!=NULL){
            if(ee==c){
                cout<< b << " ";
            }
            else{
                cout<< current->val << " ";
                current = current->next;
            }
            ee++;
        }
        
        
    }

};

int main(){
    ll akzhol;
    int a;cin>> a;
    for(int i=0;i<a;i++){
        int e;cin >> e;
        akzhol.add(e);
    }
    int  b;cin >> b;
    int  c;cin >> c;
    akzhol.solvingModa(b, c);
}