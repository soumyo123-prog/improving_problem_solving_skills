#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5;

ll n, d;
ll a[MAX + 1];

ll lb(ll i, ll s, ll e) {
  ll idx = -1;

  while (s <= e) {
    ll mid = s + (e - s) / 2;
    if (a[mid] - a[i] <= d) {
      idx = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  return idx;
}

void solve() {
  cin >> n >> d;
  for (ll i = 0; i < n; i++) cin >> a[i];

  ll ans = 0;
  for (ll i = 0; i < n - 2; i++) {
    ll idx = lb(i, i + 2, n - 1);
    if (idx != -1) {
      ll k = idx - i;
      ans += (k * (k - 1)) / 2;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
