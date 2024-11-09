#include <bits/stdc++.h>
using namespace std;


void computeLPSArray(string pattern, int M, vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pattern, string text) {
    int M = pattern.length();
    int N = text.length();
    vector<int> lps(M);
    int count = 0;
    deque<int> ako;
    computeLPSArray(pattern, M, lps);

    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            ako.push_back(i - j+1);
            count++;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    cout << count << endl;
    for(int i=0;i<ako.size();i++){
        cout << ako[i] << " ";
    }
}

int main() {
    string a,b;cin >> a >> b;
    string text;
    string pattern;
    if(a.size()>b.size()){
        text = a;
        pattern = b;
    }
    else{
        text = b;
        pattern = a;
    }
    

    KMPSearch(pattern, text);
    return 0;
}