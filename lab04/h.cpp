
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;cin >> a;
    deque<int> ako;
    for(int i=0;i<a;i++){
        int ss;cin >>ss;
        ako.push_back(ss);
    }
    sort(ako.begin(), ako.end());
    deque<int> aza;
    int era=0;
    for(int i=a-1;i>=0;i--){
        era+=ako[i];
        aza.push_back(era);
    }

    sort(aza.begin(), aza.end());
    for(int i=0;i<aza.size();i++){
        cout << aza[i] << " ";
    }
}