#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + m + 1), b(n + m + 1);
  for (ll i = 0; i < n + m + 1; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n + m + 1; i++) {
    cin >> b[i];
  }
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
