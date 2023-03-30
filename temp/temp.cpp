#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> counts(51, 0);
        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments[i] = {l, r};
            for (int j = l; j <= r; j++) {
                counts[j]++;
            }
        }
        int max_count = counts[k];
        bool ideal = true;
        for (int i = 1; i <= 50; i++) {
            if (i != k && counts[i] >= max_count) {
                ideal = false;
                break;
            }
        }
        if (ideal) {
            cout << "YES" << endl;
        } else {
            int max_removed = 0;
            for (int i = 0; i < n; i++) {
                int l = segments[i].first, r = segments[i].second;
                if (l <= k && k <= r) {
                    int removed = 0;
                    for (int j = l; j <= r; j++) {
                        if (counts[j] == max_count) {
                            removed++;
                            counts[j]--;
                        }
                    }
                    if (removed > max_removed) {
                        max_removed = removed;
                    }
                    for (int j = l; j <= r; j++) {
                        counts[j]++;
                    }
                }
            }
            if (max_removed > 0) {
                ideal = true;
                for (int i = 1; i <= 50; i++) {
                    if (i != k && counts[i] >= max_count) {
                        ideal = false;
                        break;
                    }
                }
                if (ideal) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
