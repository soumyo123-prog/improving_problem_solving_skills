#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 2000000011;

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++) {
    ll n;
    cin >> n;
    cout << "Case #" << i << ": " << binpow(n, n - 2, MOD) << endl;
  }

  return 0;
}
