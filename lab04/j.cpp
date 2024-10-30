// #include <bits/stdc++.h>
// using namespace std;

// void createBalancedArray(vector<int>& arr, vector<int>& result, int start, int end) {
//     if (start > end) return;

//     int mid = (start + end) / 2;
//     result.push_back(arr[mid]);

//     createBalancedArray(arr, result, start, mid - 1);
//     createBalancedArray(arr, result, mid + 1, end);
// }

// int main() {
//     int a;
//     cin >> a;
//     int n = a+1;
//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }

//     sort(arr.begin(), arr.end());

//     vector<int> result;
//     createBalancedArray(arr, result, 0, n - 1);

//     for (int i = 0; i < result.size(); ++i) {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void createBalancedArray(vector<int>& arr, vector<int>& result, int start, int end) {
    if (start > end) return;

    int mid = (start + end) / 2;
    result.push_back(arr[mid]);

    createBalancedArray(arr, result, start, mid - 1);
    createBalancedArray(arr, result, mid + 1, end);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> result;
    createBalancedArray(arr, result, 0, n - 1);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
