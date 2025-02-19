#include <bits/stdc++.h>
using namespace std;

void ako(int a) { 
    int b;cin >> b;
    deque<int> ako;
    for (int i = 0; i < a; i++) {
        int e;cin >> e; 
        ako.push_back(e);    
    }
    bool era = false;
    for(int i=0;i<ako.size();i++){
        if(ako[i]==1 and ako[i+1]==1){
            era = true;
        }
        else{
            era = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ako(n);
    }
    return 0;
}
