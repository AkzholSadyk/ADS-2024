#include <bits/stdc++.h>
using namespace std;

void ako(string a, string b) {
    deque<char> abs;  
    deque<char> abs2; 

    for (int i = 0; i < a.size(); i++) {
        char element = a[i];
        if (element != '#') {
            abs.pop_back();
        }
    }

    for (int i = 0; i < b.size(); i++) {
        char element = b[i];
        if (element != '#') {
            abs2.push_back(element);
        }
    }
    if(abs==abs2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

int main() {
    string a; cin >> a;
    string b; cin >> b;
    ako(a, b);

    return 0;
}
