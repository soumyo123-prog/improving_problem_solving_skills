#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (__int128)res * a % m;
    a = (__int128)a * a % m;
    b >>= 1;
  }
  return res;
}

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd((b % a), a);
}

void solve() {
  ll a, b, n;
  cin >> a >> b >> n;
  if (a == b) {
    cout << (binpow(a, n, MOD) + binpow(b, n, MOD)) % MOD << endl;
    return;
  }

  ll x = a - b;
  ll y = (binpow(a, n, x) + binpow(b, n, x)) % x;

  cout << gcd(y, x) % MOD << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
