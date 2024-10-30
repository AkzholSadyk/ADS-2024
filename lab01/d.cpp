#include <bits/stdc++.h>
using namespace std;
void ako(string a, string b){
    deque<char> first;
    deque<char> second;
    for(int i=0; i< a.size(); i++){
        first.push_back(a[i]);
        if(a[i]=='#'){
            first.pop_back();first.pop_back();
        }
    }
    for(int i=0;i<b.size();i++){
        second.push_back(b[i]);
        if(b[i]=='#'){
            second.pop_back();second.pop_back();
        }
    }

    if(first == second){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

int main(){
    string a; cin >> a;
    string b; cin >> b;
    ako(a,b);
}
