#include <bits/stdc++.h>
using namespace std;

int count1543(const vector<string>& layer) {
    string target = "1543";
    int count = 0;
    string s = "";
    for (const auto& row : layer) {
        s += row;
    }
    for (size_t i = 0; i <= s.size() - 4; ++i) {
        if (s.substr(i, 4) == target) {
            count++;
        }
    }
    return count;
}

vector<string> extractLayer(const vector<string>& carpet, int layer) {
    int n = carpet.size();
    int m = carpet[0].size();
    vector<string> result;
    for (int i = layer; i < m - layer; ++i) {
        result.push_back(string(1, carpet[layer][i]));
    }
    for (int i = layer + 1; i < n - layer; ++i) {
        result.push_back(string(1, carpet[i][m - layer - 1]));
    }
    for (int i = m - layer - 2; i >= layer; --i) {
        result.push_back(string(1, carpet[n - layer - 1][i]));
    }
    for (int i = n - layer - 2; i > layer; --i) {
        result.push_back(string(1, carpet[i][layer]));
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }
        
        int totalCount = 0;
        for (int layer = 0; layer < min(n, m) / 2; ++layer) {
            vector<string> currentLayer = extractLayer(carpet, layer);
            totalCount += count1543(currentLayer);
        }
        
        cout << totalCount << endl;
    }
    return 0;
}
