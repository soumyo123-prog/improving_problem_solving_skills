#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll lcm(ll n1, ll n2) { return ((n1 * n2) / __gcd(n1, n2)); }

void solve() {
  ll i1, i2;
  cin >> i1 >> i2;

  ll lcm12 = lcm(i1, i2);

  ll d = (lcm12 - i1) / i1;
  ll m = (lcm12 - i2) / i2;

  if (i1 > i2) {
    d++;
  } else {
    m++;
  }

  if (d > m) {
    cout << "Dasha" << endl;
  } else if (d == m) {
    cout << "Equal" << endl;
  } else {
    cout << "Masha" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
