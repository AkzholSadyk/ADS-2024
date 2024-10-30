#include <bits/stdc++.h>
using namespace std;

#define rr long long

int main(){
    rr a;cin >> a;
    rr b;cin >> b;
    deque<rr> ako;
    rr azamat = 0;
    
    rr aza = 0;
    while(a>0){
        
        sort(ako.begin(), ako.end());
        string era;cin >>era;
        if(era=="insert"){
            rr uu;cin >> uu;
            azamat ++;
            if(ako.size()< b){
                ako.push_back(uu);
                aza+=uu;
            }
                
            else if(ako.front()<uu){
                    aza-=ako.front();
                    ako.pop_front();
                    ako.push_back(uu);
                    aza+=uu;
            }
            
            
        }
        else if(era=="print"){
            cout << aza << endl;
        }

        a--;
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// #define rr long long

// int main() {
//     rr a, b;
//     cin >> a >> b;
//     priority_queue<rr, vector<rr>, greater<rr>> ako;
//     rr aza = 0;

//     for (rr i = 0; i < a; ++i) {
//         string ss;
//         cin >> ss;

//         if (ss == "print") {
//             cout << aza << endl;
//         } else if (ss == "insert") {
//             rr era;
//             cin >> era;

//             if (ako.size() < b) {
//                 ako.push(era);
//                 aza += era;
//             } else if (era > ako.top()) {
//                 aza -= ako.top();
//                 ako.pop();
//                 ako.push(era);
//                 aza += era;
//             }
//         }
//     }

//     return 0;
// }
