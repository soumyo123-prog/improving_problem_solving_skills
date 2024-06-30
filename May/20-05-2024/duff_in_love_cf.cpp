#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;
  for (ll i = 2; i * i <= n; i++) {
    while ((n % (i * i)) == 0) {
      n /= i;
    }
  }
  cout << n << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
