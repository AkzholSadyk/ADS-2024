#include <bits/stdc++.h>
using namespace std;

#define rr long long

int main(){
    rr a;cin >> a;
    priority_queue<rr> ako;
    rr erasyl;cin >> erasyl;
    
    for (rr i = 0; i < a; ++i) {
        rr ss;cin >> ss;
        ako.push(ss);
    }

    rr aza = 0;

    
    while (ako.size()!=1) {
        rr first = ako.top();
        ako.pop();
        rr second = ako.top();
        

        if(first>erasyl and second>erasyl){
            aza++;
        }
        else{
            break;
        }
    }
    if(aza!=0){
        cout << aza;}
    else{
        cout << -1;
    }

    return 0;
}