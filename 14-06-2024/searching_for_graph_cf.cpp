#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, p;
  cin >> n >> p;

  vector<pair<ll, ll>> v;
  ll remEdges = 2 * n + p;

  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      cout << i + 1 << ' ' << j + 1 << endl;
      remEdges--;
      if (remEdges == 0) return;
    }
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
