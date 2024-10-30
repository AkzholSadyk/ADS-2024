
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;cin >> a;
    deque<int> ako;
    for(int i=0;i<a;i++){
        int ss;cin >> ss;
        ako.push_back(ss);
    }

    sort(ako.begin(), ako.end());
    while(ako.size()!=1){
        int b = ako.back();
        ako.pop_back();
        int c = ako.back();
        if(b>c){
            ako.pop_back();
            int d = b-c;
            ako.push_back(d);
            sort(ako.begin(), ako.end());
        }
        else if(b == c){
            ako.pop_back();
            if(ako.empty()){
                break;
            }
        }
    }
    
    if(!ako.empty()){
        for(int i=0;i<ako.size();i++){
            cout << ako[i] << " ";
        }
    }
    else{
        cout << 0;
    }
}