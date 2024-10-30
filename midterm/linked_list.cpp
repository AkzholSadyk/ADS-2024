#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    int sum;
    node* next;
    node* prev;
    node(int x){
        val = x;
        sum = x;
        prev = next = nullptr;
    }
};

struct dll{
    private:
        node* head;
        node* tail;
        int len;

    public: 
        dll(){
            head = tail = nullptr;
            len = 0;
        }   
        

        void add(int x){
            node* block = new node(x);
            if(head == nullptr){
                head = tail = block;
                block -> sum = x;
            }
            else{
                tail -> next = block;
                block -> prev = tail;
                tail = block;  
                block -> sum = max(block -> sum, block -> prev -> sum + block -> sum);
            }
            len += 1;
        }

        int takeMaxSum(){
            node* step = head;
            int mx = head -> sum;
            while(step != nullptr){
                mx = max(mx, step -> sum);
                step = step -> next;
            }
            return mx;
        }

};

void solve(){
    dll ll;
    int n; cin >> n;
    for(int i =0; i < n; ++i){
        int num; cin >> num;
        ll.add(num);
    }
    cout << ll.takeMaxSum();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while(t--){
        solve();    
    }
}