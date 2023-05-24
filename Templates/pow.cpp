#include<bits/stdc++.h>
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main()
{
    int ans = modpow(2,3, (int)1e9+7);
    ans = modpow(2,ans, (int)1e9+7);

    cout << ans << endl;
    
    return 0;
}