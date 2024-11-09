#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция для создания массива LPS (Longest Prefix Suffix)
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

// Функция для поиска максимального суффикса, который является префиксом
int findMaxSuffixPrefix(string text, string pattern) {
    int M = pattern.length();
    int N = text.length();
    vector<int> lps(M);
    computeLPSArray(pattern, M, lps);
    int i = 0, j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == M) {
            return j;
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return j;
}

int main() {
    string previousCity;
    cin >> previousCity;
    int n;
    cin >> n;
    vector<string> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    vector<string> possibleCities;
    int maxLength = 0;
    for (const string& city : cities) {
        int length = findMaxSuffixPrefix(previousCity, city);
        if (length > maxLength) {
            maxLength = length;
            possibleCities.clear();
            possibleCities.push_back(city);
        } else if (length == maxLength) {
            possibleCities.push_back(city);
        }
    }

    cout << possibleCities.size() << endl;
    for (const string& city : possibleCities) {
        cout << city << endl;
    }

    return 0;
}
