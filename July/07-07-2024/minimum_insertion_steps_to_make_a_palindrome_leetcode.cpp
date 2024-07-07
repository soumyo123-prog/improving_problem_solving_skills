#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int minInsertions(string s) {
  int n = s.size();

  int dp[n][n];
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
    if (i + 1 < n) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 0;
      } else {
        dp[i][i + 1] = 1;
      }
    }
  }

  for (int i = 3; i <= n; i++) {
    for (int j = 0; j + i - 1 < n; j++) {
      if (s[j] == s[j + i - 1]) {
        dp[j][j + i - 1] = dp[j + 1][j + i - 2];
      } else {
        dp[j][j + i - 1] = 1 + min(dp[j + 1][j + i - 1], dp[j][j + i - 2]);
      }
    }
  }

  return dp[0][n - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << minInsertions("zzazz") << endl;
  cout << minInsertions("mbadm") << endl;
  cout << minInsertions("leetcode") << endl;

  return 0;
}
