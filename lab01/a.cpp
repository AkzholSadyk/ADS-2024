/*#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n, int a, deque<int>& arr)
{   
	
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            arr.push_back(p);
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    cout << arr[a];
}

// Driver Code
int main()
{   
    int a; 
    cin >> a;
    int n = 100000;
    deque<int> arr;
	arr.push_front(2);
    SieveOfEratosthenes(n, a, arr);
    return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    stack<int> arr;
    arr.push(2);
    for(int i = 3; arr.size() < n; i++){
        for(int j = 2; j < i; j++){
            if(i%j == 0){
                break;
            }else if(i%j != 0 && i-1==j){
                arr.push(i);
            }
        }
    }
    cout << arr.top();
    
}*/

#include <bits/stdc++.h>
using namespace std;

void prime(vector<int>& ads, int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            ads.push_back(p);
        }
    }
}


void super_prime(vector<int>& ok, const vector<int>& ads) {
    for (int i = 0; i < ads.size(); i++) {
        if (i + 1 < ads.size() && ads[i + 1] <= ads.size()) {
            ok.push_back(ads[ads[i + 1] - 1]);
        }
    }
}


void answer_prime(int d, const vector<int>& ok) {
    if( d==1){
      cout<< 3;
    }
    else if (d > 1 && d <= ok.size()) {
        cout << ok[d - 2];
    } 
}

int main() {
    int d;
    cin >> d;
    vector<int> ads;
    vector<int> ok;
    int limit = 10000;
    prime(ads, limit);
    super_prime(ok, ads);
    answer_prime(d, ok);
    return 0;
}


