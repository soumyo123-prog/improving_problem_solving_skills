#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<pair<ll, ll>> rows(n + 1, {0, 0}), cols(m + 1, {0, 0});
  for (ll i = 1; i <= k; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    if (x == 1) {
      rows[y] = {z, i};
    } else {
      cols[y] = {z, i};
    }
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      if (rows[i].second > cols[j].second) {
        cout << rows[i].first << ' ';
      } else {
        cout << cols[j].first << ' ';
      }
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
