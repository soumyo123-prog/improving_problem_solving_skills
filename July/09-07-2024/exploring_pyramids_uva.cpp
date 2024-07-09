#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1000000000;

void solve(string s) {
  ll n = s.size();

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (ll i = 0; i < n; i++) {
    dp[i][i] = 1;
    if (i + 2 < n && s[i] == s[i + 2]) {
      dp[i][i + 2] = 1;
    }
  }

  for (ll i = 5; i <= n; i += 2) {
    for (ll j = 0; j + i - 1 < n; j++) {
      ll k = j + i - 1;
      if (s[j] == s[k]) {
        for (ll l = j + 2; l <= k; l++) {
          if (s[j] == s[l]) {
            dp[j][k] += ((dp[j + 1][l - 1] % MOD) * (dp[l][k] % MOD)) % MOD;
            dp[j][k] %= MOD;
          }
        }
      }
    }
  }

  cout << dp[0][n - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (cin >> s) {
    solve(s);
  }
  return 0;
}
