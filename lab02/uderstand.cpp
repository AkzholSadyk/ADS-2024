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
            return;
            }
        else{
            head->next = block;
            tail = tail->next;
            }
            len++;
        }

    void solving(){
        node* ako = head;
        int a = 1;
        while(ako!=NULL){
            if(a%2==1){
                cout<< ako->val << " ";
            }
        }
        ako = ako->next;
        a++;
        
        }

    };

    // void print(){
    //     node* arman  = head;   
    //     while(arman!=NULL){
    //         cout << arman->val << " ";
    //         arman = arman -> next;
    //             }
    //     }       
    // };

int main(){
    int x;
    cin >> x;

    ll akzhol; 
    for(int i =0;i < x; ++i){
        int num; cin >> num;
        akzhol.add(num);
    }

    akzhol.solving();
    return 0;
    }

