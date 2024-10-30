

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
    
    void solvingModa(){
        node* current = head;
        vector<int> ako;
        unordered_map<int,int> era;

        while(current){
            ako.push_back(current->val);
            current = current->next;
        }
        
        for(int num:ako){
            era[num]++;
        }

        int max = 0;
        for(const auto& a:era){
            if(a.second > max){
                max = a.second;
            }
        }
        vector<int> aza;
        for(const auto& a:era){
            if(a.second == max){
                aza.push_back(a.first);
            }
        }
        sort(aza.begin(), aza.end());
        reverse(aza.begin(), aza.end());
        for(int i=0;i<aza.size();i++){
            cout<< aza[i] << " ";
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
    akzhol.solvingModa();
}