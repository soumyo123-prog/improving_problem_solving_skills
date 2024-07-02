#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int longestCommonSubsequence(string s1, string s2) {
  int n = s1.size(), m = s2.size();
  int dp[n + 1][m + 1];
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

void solve(string s1, string s2, int testCase) {
  int lcs = longestCommonSubsequence(s1, s2);

  cout << "Case #" << testCase << ": you can visit at most " << lcs
       << " cities." << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  vector<string> v;
  int testCase = 0;
  while (getline(cin, s)) {
    if (s[0] == '#') {
      break;
    }
    v.push_back(s);
    if (v.size() == 2) {
      testCase++;
      solve(v[0], v[1], testCase);
      v.clear();
    }
  }

  return 0;
}
