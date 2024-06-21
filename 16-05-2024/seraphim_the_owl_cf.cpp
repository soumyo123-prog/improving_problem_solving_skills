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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<ll> sums(n);
  ll sumTillNow = 0;

  for (int i = n - 1; i >= 0; i--) {
    sums[i] = sumTillNow + a[i];
    sumTillNow += min(a[i], b[i]);
  }

  ll ans = LLONG_MAX;
  for (int i = 0; i < m; i++) {
    ans = min(ans, sums[i]);
  }
  cout << ans << endl;
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
