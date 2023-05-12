#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> f(n+1, 0);
    f[2] = 6;

    for (int k = 3; k <= n; k++) {
        f[k] = (k*k - 1) * (f[k-2]?f[k-2]:1);
    }

    for (int k = 1; k <= n; k++) {
        cout << f[k] << "\n";
    }

    return 0;
}
