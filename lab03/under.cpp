#include <bits/stdc++.h>

using namespace std;

#define ll long long



void solve(){
    int t; cin >> t;
    vector <ll> v(t, 0);
    for(int i =0; i < t; ++i){
        cin >> v[i];
    }
    int n, m; cin >> n >> m;
    ll arr[n][m];
    for(int i =0; i <n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }
    }
    for(int in = 0; in < t; ++in){
        ll ans1 = -1, ans2;
        for(int i =0; i < m; ++i){
            ll l = 0, r = n - 1;
            while(l <= r){
                ll mid = l + (r - l) / 2;
                if(v[in] == arr[mid][i]){
                    ans1 = mid;
                    break;
                }
                else if(v[in] < arr[mid][i])
                    l = mid + 1;
                else   
                    r = mid - 1;    
            }
            if(ans1 != -1){
                ans2 = i;
                break;
            }
        }
        if(ans1 == -1) cout << -1 << endl;
        else cout << ans1 << ' ' << ans2 << endl;
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while(t--){
        solve();    
    }
}