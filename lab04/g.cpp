#include <bits/stdc++.h>
// aksa001
using namespace std;
 
int main(){
    int t;cin >> t;
    vector<int> ako(t);
    for(int i=0;i<t;i++){
        cin>>ako[i];
    }
    for(int i=0;i<t;i++){
        int n=ako[i];
        int m=0;
        for(int b=1;b<n;b++){
            int a=n-b;
            if(a>0){
                m++;
            }
        }
        cout<<m<<endl;
    }

}