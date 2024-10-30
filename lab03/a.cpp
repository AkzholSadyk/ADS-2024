#include <bits/stdc++.h>

using namespace std;
void solving(){
    int a;cin >> a;
    vector<long long> ako(a, 0);
    for(int i=0;i<a;i++){
        cin>> ako[i];
    }
    int b,c;cin >> b >> c;
    long long era[b][c];
    for(int i=0;i<b;i++){
        for(int j=0;j<c;j++){
            cin >> era[i][j];
        }
    }
    for(int u = 0;u<a;u++){
        long long answer1 = -1, answer2;
        for(int i=0;i<c;i++){
            long long l = 0, r = b-1;
            while(l <= r){
                long long mid = l + (r-l)/2;
                if(ako[u] == era[mid][i]){
                    answer1 = mid;
                    break;
                }
                else if(ako[u] < era[mid][i]){
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
            if(answer1!=-1){
                answer2 = i;
                break;
            }
        }
        if(answer1 == -1) cout << -1 << endl;
        else cout << answer1 << " " << answer2 << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while(t--){
        solving();    
    }
}