// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int a;cin >> a;
//     map<int, int> ako;
//     for(int i=0;i<a;i++){
//         string era; cin >> era;
//         if(era == "insert"){
//             int ss;cin >> ss;
//             for(const auto& ss:ako){
//                 if(ss==ako.first){
//                     ako.second++;
//                 }
//                 else{
//                     ako.first = ss;
//                 }
//             }
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int a;
//     cin >> a;
//     map<int, int> ako;

//     for (int i = 0; i < a; i++) {
//         string era;
//         cin >> era;

//         if(era== "insert") {
//             int ss;
//             cin >> ss;
//             ako[ss]++;
//         }
//         if(era== "cnt"){
//             int ss;cin >> ss;
//             cout << ako[ss];
//         }
//         if(era== "delete"){
//             int ss;cin >> ss;
//             ako[ss]--;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    map<int, int> ako;

    for (int i = 0; i < a; i++) {
        string era;
        cin >> era;

        if (era == "insert") {
            int ss;
            cin >> ss;
            ako[ss]++;
        } else if (era == "cnt") {
            int ss;
            cin >> ss;
            cout << ako[ss] << endl;
        } else if (era == "delete") {
            int ss;
            cin >> ss;
            if (ako[ss] > 0) {
                ako[ss]--;
                if (ako[ss] == 0) {
                    ako.erase(ss);
                }
            }
        }
    }

    return 0;
}
