#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll lcm(ll a1, ll a2, ll a3, ll a4) {
  ll ans = (a1 * a2) / __gcd(a1, a2);
  ans = (ans * a3) / __gcd(ans, a3);
  ans = (ans * a4) / __gcd(ans, a4);
  return ans;
}

void solve() {
  while (1) {
    ll n, t;
    cin >> n >> t;
    if (n == 0 && t == 0) break;

    vector<ll> ct(n), tl(t);
    for (ll i = 0; i < n; i++) cin >> ct[i];
    for (ll i = 0; i < t; i++) cin >> tl[i];

    for (ll i = 0; i < t; i++) {
      ll l1 = LLONG_MIN, l2 = LLONG_MAX;
      for (ll j1 = 0; j1 < n; j1++) {
        for (ll j2 = j1 + 1; j2 < n; j2++) {
          for (ll j3 = j2 + 1; j3 < n; j3++) {
            for (ll j4 = j3 + 1; j4 < n; j4++) {
              ll lcm4 = lcm(ct[j1], ct[j2], ct[j3], ct[j4]);
              ll tl1 = (tl[i] / lcm4) * lcm4;
              ll tl2 = tl1;
              if (tl1 < tl[i]) tl2 += lcm4;
              l1 = max(l1, tl1);
              l2 = min(l2, tl2);
            }
          }
        }
      }
      cout << l1 << ' ' << l2 << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
