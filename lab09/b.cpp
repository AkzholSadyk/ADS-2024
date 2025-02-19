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


void KMPSearch(string pattern, string text, int c) {
    int M = pattern.length();
    int N = text.length();
    vector<int> lps(M);

    
    computeLPSArray(pattern, M, lps);
    int count =0;
    int i = 0;
    int j = 0; 
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
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
  
    if(c <= count){
        cout <<"YES"; 
    }
    else{
        cout << "NO";
    }
}

int main() {
    string pattern;cin >> pattern;
    int c;cin >> c;
    string text;cin >> text;
    
    KMPSearch(pattern, text, c);

    return 0;
}