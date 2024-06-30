#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, k, pb, ps;
  cin >> n >> k >> pb >> ps;

  vector<ll> p(n), a(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> a[i];

  ll len = min(k, n);
  vector<ll> a1(len), a2(len);

  ll s1 = 0, s2 = 0;
  for (int i = 0; i < len; i++) {
    a1[i] = s1 + (k - i) * a[pb - 1];
    a2[i] = s2 + (k - i) * a[ps - 1];
    s1 += a[pb - 1];
    s2 += a[ps - 1];
    pb = p[pb - 1];
    ps = p[ps - 1];
  }

  ll sb = INT_MIN, ss = INT_MIN;
  for (int i = 0; i < len; i++) {
    sb = max(sb, a1[i]);
    ss = max(ss, a2[i]);
  }

  if (sb > ss) {
    cout << "Bodya" << endl;
  } else if (sb == ss) {
    cout << "Draw" << endl;
  } else {
    cout << "Sasha" << endl;
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
