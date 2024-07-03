#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void print_reduced_fraction(ll num, ll den) {
  ll gcd = __gcd(num, den);
  while (gcd > 1) {
    num /= gcd;
    den /= gcd;
    gcd = __gcd(num, den);
  }
  cout << num << " / " << den << endl;
}

void solve(ll n, ll m) {
  vector<vector<ll>> a(n, vector<ll>(m));
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
      if (j == m - 1) sum += a[i][j];
    }
  }

  for (ll i = 0; i < n; i++) {
    print_reduced_fraction(a[i][m - 1], sum);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    solve(n, m);
  }
  return 0;
}
