#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), b(n + 1);
  for (ll i = 0; i < n; i++) cin >> a[i];
  for (ll i = 0; i < n + 1; i++) cin >> b[i];

  ll oper = 0, to = LLONG_MAX;
  bool flag = false;
  for (ll i = 0; i < n; i++) {
    oper += abs(a[i] - b[i]);
    if ((a[i] <= b[n] && b[n] <= b[i]) || (b[i] <= b[n] && b[n] <= a[i])) {
      to = 1;
    } else {
    }
    to = min(to, min(1 + abs(a[i] - b[n]), 1 + abs(b[i] - b[n])));
  }

  oper += to;
  cout << oper << endl;
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
