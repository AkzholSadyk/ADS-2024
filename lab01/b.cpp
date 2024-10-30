#include <bits/stdc++.h>
using namespace std;
int main(){
    int a; cin >> a;
    deque<int> ako;
    deque<int> ads;
    for(int i=0;i<a;i++){
        int b;cin >>  b;
        ako.push_back(b);
    }
    for(int i=0; i<ako.size();  i++){
        int e = -1;
        for(int j=i-1;j>=0;j--){
            if(ako[j]<=ako[i]){
                e = ako[j];
                break;
            }
        }
        ads.push_back(e);
    }

    for(int i=0;i<ads.size();i++){
        cout << ads[i] << " ";
    }
}

















/*void for_solving_stack(deque<int>& abs, deque<int>& ok, deque<int>& ako){
    for(int i = 0; i<abs.size();i++){
        int men = -1;
        for(int j=i-1;j>=0;--j){
            if(abs[j] <= abs[i]){
               men = abs[j];
               break;
            }
        }
        ako.push_back(men);
    }
}

int main(){
    int a;
    deque<int> ok;
    deque<int> abs;
    deque<int> ako;
    for(int i=0; i<a;i++){

        int just_number; cin >> just_number;
        abs.push_back(just_number);
    }
    for(int i =0 ; i < a; ++i){
        cout << abs[i] << ' ';
    }
    for_solving_stack(abs, ok, ako);
    for(int i=0; i<ako.size();i++){
        cout<< ako[i] << " ";
    }
    return 0;
 }*/