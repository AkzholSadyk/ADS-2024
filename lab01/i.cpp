#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;cin >> a;
    deque<char> elite;
    for(int i=0;i<a;i++){
        char b;cin >> b;
        elite.push_back(b);
    }

    for(int i=0;i<elite.size();i++){
        cout<< elite[i];
    }
    
    
}