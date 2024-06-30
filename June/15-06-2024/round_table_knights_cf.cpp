#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void printYesOrNo(bool flag) {
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

bool solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  vector<ll> b;
  for (ll i = 3; i <= n; i++) {
    if (n % i == 0) {
      b.push_back(i);
    }
  }

  for (ll i = 0; i < b.size(); i++) {
    vector<ll> cnt(n, 0);
    ll dis = n / b[i];
    for (ll j = dis; j < n; j++) {
      if (a[j] == 0) continue;
      if (a[j - dis] == 1) {
        cnt[j] = 1 + cnt[j - dis];
      }
    }
    for (ll j = n - dis; j < n; j++) {
      if (cnt[j] == b[i] - 1) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    printYesOrNo(solve());
  }
  return 0;
}
