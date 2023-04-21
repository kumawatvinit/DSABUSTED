#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> queries(m);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }
    sort(arr.begin(), arr.end());
    vector<long long> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }


    vector<long long> costs(m);
    for (int i = 0; i < m; i++) {
        int target = queries[i];
        int index = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        int left_count = index;
        int right_count = n - index;
        long long left_sum = prefix_sum[index];
        long long right_sum = prefix_sum[n] - prefix_sum[index];
        long long cost = 0;
        // if (left_count >= right_count) {
            cost = (1LL * (left_count - right_count) * target - left_sum + right_sum);
        // } else {
            // cost = (left_sum - right_sum - 1LL * (right_count - left_count) * target);
        // }
        costs[i] = cost;
    }
    for (int i = 0; i < m; i++) {
        cout << costs[i] << " ";
    }
    cout << endl;
    return 0;
}
