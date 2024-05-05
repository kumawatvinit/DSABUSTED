#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minServers(vector<int>& servers, int expected_load) {
    int n = servers.size();
    vector<int> prev(expected_load + 1, 0);
    vector<int> curr(expected_load + 1, INT_MAX);

    // // Step 1: Initialize DP Table (using prev)
    // fill(prev.begin(), prev.end(), INT_MAX);
    // prev[0] = 0;

    // Step 2: Fill DP Table
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= expected_load; ++j) {
            if (servers[i - 1] > j) {
                curr[j] = prev[j];
            } else {
                curr[j] = min(prev[j], 1 + prev[j - servers[i - 1]]);
            }
        }
        // Update prev with curr for the next iteration
        prev = curr;
    }

    // Step 3: Check for Solution
    if (curr[expected_load] == INT_MAX)
        return -1;

    // Step 4: Return Result
    return curr[expected_load];
}

int main() {
    // Example usage
    vector<int> servers = {1, 2, 2, 4, 4};
    int expected_load = 10;
    cout << "Minimum number of servers required: " << minServers(servers, expected_load) << endl;

    return 0;
}
