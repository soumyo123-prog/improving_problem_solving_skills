#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const string divisible = "Divisible";
const string notDivisible = "Not divisible";

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<bool>> dp(n, vector<bool>(k, false));
  dp[0][(a[0] % k + k) % k] = true;

  for (int i = 1; i < n; i++) {
    int num = abs(a[i]);
    for (int j = 0; j < k; j++) {
      if (dp[i - 1][j]) {
        dp[i][((j + (num % k)) % k + k) % k] = true;
        dp[i][((j - (num % k)) % k + k) % k] = true;
      }
    }
    // for (int j = 0; j < k; j++) {
    //   cout << dp[i][j] << ' ';
    // }
    // cout << endl;
  }

  if (dp[n - 1][0]) {
    cout << divisible << endl;
  } else {
    cout << notDivisible << endl;
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
