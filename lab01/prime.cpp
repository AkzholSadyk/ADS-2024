/*#include <bits/stdc++.h>
using namespace std;

void ako(int a) {  
    bool ok = false;
    if (a == 2) {
        cout << "YES";
    } else {
        for (int i = 2; i < a; i++) {
            if (a % i == 0) { 
                ok = false;
                break;
            } else if (a%i!=0 && i + 1 == a) {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}

int main() {
    int a; cin >> a;
    ako(a);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
void ako(int a){
    bool ok=false;
    if(a==2){
        cout << "YES";
        
    }
    else{
        for(int i=2; i<a; i++){
            if(a%i==0){
                break;
            }
            else if(a %i!=0 && i+1==a){
                ok = true;
            }
        }
        if(ok){
         cout << "YES";
        }
        else{
         cout <<"NO";
        }
    }

}
int main(){
    int a; cin >> a;
    ako(a);
    return 0;
}





*/
#include <bits/stdc++.h>
using namespace std;



void ako(){
    deque<int> oo;
    char ok;
    int san;
    while(cin >> ok){
        
        if(ok== '+'){
            cin >> san;
            oo.push_front(san);
        }
        else if(ok == '-'){
            cin >> san;
            oo.push_back(san);
        }
        else if(ok == '*'){
            if(!oo.empty()){
              int sum = oo.front()+oo.back();
              cout<< sum<< endl;
              oo.pop_front();
              if(!oo.empty()){
                oo.pop_back();
              }}
            else{
                cout<< "error"<< endl;
            }}
        else if(ok == '!'){
            break;
        }


    }

}
int main(){
    ako();
    return 0;
}
