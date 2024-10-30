#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;cin >> a;
    int nurik[a];
    int era[a];
    for(int i=0;i<a;i++){
        cin >> nurik[i];
    }

    for(int i=0;i<a;i++){
        int ss = nurik[i];
        for(int j=0;j<a;j++){
            if(ss == nurik[j]){
                era[j]++;
            }
        }
    }

    for(int i=0;i<a;i++){
        cout << era[i] << " ";
    }

    
}