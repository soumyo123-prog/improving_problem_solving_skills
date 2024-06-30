#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;

void solve() {
  ll x, y, n;
  cin >> x >> y >> n;

  vector<ll> a = {x, y, y - x, -x, -y, x - y};
  vector<ll> indices = {5, 0, 1, 2, 3, 4};

  ll ans = a[indices[n % 6]];
  if (ans > 0) {
    ans = ans % MOD;
  } else {
    ans = ((ans % MOD) + MOD) % MOD;
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
