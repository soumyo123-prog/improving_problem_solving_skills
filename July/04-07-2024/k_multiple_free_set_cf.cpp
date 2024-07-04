#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  set<ll> sb, rem;
  for (ll i = 0; i < n; i++) {
    if (a[i] % k != 0) {
      sb.insert(a[i]);
    } else {
      rem.insert(a[i]);
    }
  }

  while (!rem.empty()) {
    ll last = *rem.rbegin();
    rem.erase(rem.find(last));
    if (sb.find(last / k) == sb.end() && sb.find(last * k) == sb.end()) {
      sb.insert(last);
    }
  }

  cout << sb.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
