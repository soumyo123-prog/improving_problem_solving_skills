#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> s1(n), s2(n);
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    s1[i] = {x, i};
    s2[i] = {y, i};
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  string r1(n, '0'), r2(n, '0');
  for (ll i = 0; i < n / 2; i++) {
    r1[s1[i].second] = '1';
    r2[s2[i].second] = '1';
  }

  if (n % 2 == 0) {
    if (s1[n / 2].first < s2[n / 2 - 1].first) {
      r1[s1[n / 2].second] = '1';
    } else if (s2[n / 2].first < s1[n / 2 - 1].first) {
      r2[s2[n / 2].second] = '1';
    }
  } else {
    if (s1[n / 2].first < s2[n / 2].first) {
      r1[s1[n / 2].second] = '1';
    } else {
      r2[s2[n / 2].second] = '1';
    }
  }

  cout << r1 << endl;
  cout << r2 << endl;
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
