#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int N;

    for (int i = N; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
            count += 1;
        }
    }
}
// O(N)
/*
T(n) = n+n/2+n/4+n/8+....
T(n) = n+1/2(n+n/2+n/4+...)
T(n) = n+1/2T(n)
T(n) = 2n
*/