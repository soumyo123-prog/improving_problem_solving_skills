#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string irreducible_fraction(ll a, ll b) {
  ll gcd = __gcd(a, b);
  return to_string(a / gcd) + "/" + to_string(b / gcd);
}

void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  ll total = n * n;

  vector<ll> ones;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '1') {
      ones.push_back(i);
    }
  }

  ll probable = ones.size(), idx = ones.size() - 1;
  for (ll i = ones.size() - 2; i >= 0; i--) {
    while (idx > i && ones[idx] - ones[i] > k) {
      idx--;
    }
    if (idx > i) probable += idx - i;
  }
  idx = 0;
  for (ll i = 1; i < ones.size(); i++) {
    while (idx < i && ones[i] - ones[idx] > k) {
      idx++;
    }
    if (idx < i) probable += i - idx;
  }

  if (ones.size() == 0 || probable == 0) {
    cout << "0/1" << endl;
    return;
  }

  cout << irreducible_fraction(probable, total) << endl;
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
