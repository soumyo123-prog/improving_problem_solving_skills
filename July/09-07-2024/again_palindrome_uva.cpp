#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  string s;
  cin >> s;

  ll n = s.size();
  ll dp[n][n];
  for (ll i = 0; i < n; i++) {
    dp[i][i] = 1;
    if (i + 1 < n) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 3;
      } else {
        dp[i][i + 1] = 2;
      }
    }
  }

  for (ll i = 3; i <= n; i++) {
    for (ll j = 0; j + i - 1 < n; j++) {
      if (s[j] == s[j + i - 1]) {
        dp[j][j + i - 1] = 1 + dp[j][j + i - 2] + dp[j + 1][j + i - 1];
      } else {
        dp[j][j + i - 1] =
            dp[j][j + i - 2] + dp[j + 1][j + i - 1] - dp[j + 1][j + i - 2];
      }
    }
  }

  cout << dp[0][n - 1] << endl;
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
