#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;cin >> a;
    
    deque<char> ads;
    
    
    for(int i=0;i<a.size();i++){
        ads.push_back(a[i]);
        for(int j=1;j<ads.size();j++){
            if(ads[j-1]==ads[j]){
                ads.pop_back();
                ads.pop_back();
            }
        }
    }
    if(ads.empty()){
        cout<< "YES";
    }
    else{
        cout<< "NO";
    }
    return 0;
}