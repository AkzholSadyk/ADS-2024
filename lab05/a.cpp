// #include <bits/stdc++.h>
// using namespace std;

// #define rr long long

// int main(){
//     rr a;cin >> a;
//     priority_queue<rr, vector<rr>, greater<rr>> ako;

    
//     for (rr i = 0; i < a; ++i) {
//         rr ss;cin >> ss;
//         ako.push(ss);
//     }

//     rr aza = 0;

    
//     while (ako.size() > 1) {
//         rr first = ako.top();
//         ako.pop();
//         rr second = ako.top();
//         ako.pop();

//         rr era = first + second;
//         aza += era;

        
//         ako.push(era);
//     }

//     cout << aza;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(const vector<int>& nums) {
    if (nums.size() < 2) {
        cerr << "Unable to execute: there are less than two elements in the array." ;
        return INT_MIN;
    }

    int first = INT_MIN, second = INT_MIN;
    for (int num : nums) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }

    if (second == INT_MIN) {
        cerr << "Unable to execute: there are less than two distinct elements in the array." ;
        return INT_MIN;
    }

    return second;
}

int main() {
    int ako;
    cin >> ako;
    vector<int> nums(ako); 
    for (int i = 0; i < ako; i++) {
        cin >> nums[i];
    }
    int result = findSecondLargest(nums);
    if (result != INT_MIN) {
        cout << "Second largest element: " << result << endl;
    }
    return 0;
}
