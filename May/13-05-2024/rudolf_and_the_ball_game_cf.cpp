#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<bool>> a(m + 1, vector<bool>(n + 1, false));
  a[0][x] = true;

  for (int i = 1; i <= m; i++) {
    int d;
    char c;
    cin >> d >> c;
    for (int j = 1; j <= n; j++) {
      int cw = (j + d) % n;
      if (cw == 0) cw = n;
      int acw = (j + n - d % n) % n;
      if (acw == 0) acw = n;
      if (a[i - 1][j]) {
        if (c == '0') {
          a[i][cw] = true;
        } else if (c == '1') {
          a[i][acw] = true;
        } else {
          a[i][cw] = true;
          a[i][acw] = true;
        }
      }
    }
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (a[m][i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (auto i : ans) cout << i << ' ';
  cout << endl;
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
