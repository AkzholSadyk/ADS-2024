#include <bits/stdc++.h>
using namespace std;

bool ako(const vector<int>& nums, int target) {
    unordered_set<int> current, next;
    current.insert(nums[0]);

    for (int i = 1; i < nums.size(); ++i) {
        next.clear();
        for (int val : current) {
            next.insert(val + nums[i]);
            next.insert(val * nums[i]);
        }
        current.swap(next);
    }

    return current.count(target) > 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        if (ako(nums, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
