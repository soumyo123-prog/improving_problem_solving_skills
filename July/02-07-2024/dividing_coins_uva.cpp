#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  ll sum = 0;
  for (ll i = 0; i < n; i++) sum += a[i];

  vector<vector<ll>> dp(sum / 2 + 1, vector<ll>(n + 1, 0));

  for (ll i = 1; i <= sum / 2; i++) {
    for (ll j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j - 1];
      if (i >= a[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - a[j - 1]][j - 1] + a[j - 1]);
      }
    }
  }

  cout << abs(2 * dp[sum / 2][n] - sum) << endl;
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
