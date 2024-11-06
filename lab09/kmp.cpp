#include <iostream>
#include <vector>
using namespace std;

// Function to create the longest prefix suffix (LPS) array
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

// KMP algorithm for pattern matching
void KMPSearch(string pattern, string text, int c) {
    int M = pattern.length();
    int N = text.length();
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps array)
    computeLPSArray(pattern, M, lps);
    int count =0;
    int i = 0; // index for text
    int j = 0; // index for pattern
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
    // cout << count << endl;
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
    
    

    // if(a.size()>b.size()){
    //     text = a;
    //     pattern = b;
    // }
    // else{
    //     text = b;
    //     pattern = a;
    // }
    KMPSearch(pattern, text, c);
    // if(c <= KMPSearch(pattern, text)){
    //     cout <<"YES"; 
    // }
    // else{
    //     cout << "NO";
    // }
    
    return 0;
}