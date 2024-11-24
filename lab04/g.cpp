#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        map<long long, long long> freq;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<long long> candidates;
        for (const auto& pair : freq) {
            if (pair.second >= 2) {
                candidates.push_back(pair.first);
            }
        }

        if (candidates.size() < 2) {
            cout << "NO" << endl;
            continue;
        }

        sort(candidates.begin(), candidates.end());
        long long max_area = 0;
        vector<long long> best_coords(8);

        for (size_t i = 0; i < candidates.size(); i++) {
            for (size_t j = i + 1; j < candidates.size(); j++) {
                long long x1 = candidates[i];
                long long x2 = candidates[j];
                long long area = (x2 - x1) * (x2 - x1);
                if (area > max_area) {
                    max_area = area;
                    best_coords = {x1, x1, x2, x1, x1, x2, x2, x2};
                }
            }
        }

        if (max_area == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (long long coord : best_coords) {
                cout << coord << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
