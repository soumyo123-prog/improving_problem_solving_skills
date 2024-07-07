#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6;
bool isNotPrime[MAX + 1];

void sieve() {
  isNotPrime[1] = true;
  for (ll i = 2; i <= MAX; i++) {
    if (!isNotPrime[i]) {
      for (ll j = i * i; j <= MAX; j += i) {
        if (!isNotPrime[j]) {
          isNotPrime[j] = true;
        }
      }
    }
  }
}

void printYesOrNo(bool flag) {
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  for (ll i = 0; i < n; i++) {
    ll root = sqrt(a[i]);
    if ((root * root == a[i]) && !isNotPrime[root]) {
      printYesOrNo(true);
    } else {
      printYesOrNo(false);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();
  solve();
  return 0;
}
