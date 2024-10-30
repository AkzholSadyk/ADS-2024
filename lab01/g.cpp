#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    int a = 1000000;
    vector<int> prime;
    vector<int> super_prime;
    prime.push_back(2);

    for (int i = 3; i < a; i++) {
        bool ako = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                ako = false;
                break;
            }
        }
        if (ako) {
            prime.push_back(i);
        }
    }

    super_prime.push_back(3);
    super_prime.push_back(5);
    for(int i=5;i < prime.size();i++){
        bool ako =true;
        for(int j =2; j<=sqrt(i); j++){
            if(i%j==0){
                ako = false;
                break;
            }
        }
        if(ako){
            super_prime.push_back(prime[i-1]);
        }
    }
    
    /*for(int i=0;i<super_prime.size();i++){
        cout << super_prime[i] << " ";
    }*/
   cout << super_prime[n-1];

    return 0;
}
