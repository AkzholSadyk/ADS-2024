
#include <bits/stdc++.h>
using namespace std;
#define rr long long
int main() {
    rr a, b;
    cin >> a >> b;
    priority_queue<rr> ako;

    
    for (rr i = 0; i < a; ++i) {
        rr ss;cin >> ss;
        ako.push(ss);
    }

    rr aza = 0;

   
    for (rr i = 0; i < b; ++i) {
        rr era = ako.top();
        ako.pop();
        aza += era;
        ako.push(era - 1);
    }

    cout << aza;

    return 0;
}
