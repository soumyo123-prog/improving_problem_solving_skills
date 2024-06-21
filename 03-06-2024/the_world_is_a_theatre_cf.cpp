#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<vector<uint64_t>> permutation_table(uint64_t n) {
  vector<vector<uint64_t>> permTable(n + 1, vector<uint64_t>(n + 1, 0));
  for (uint64_t i = 0; i <= n; i++) {
    permTable[i][0] = 1;
  }
  for (uint64_t i = 1; i <= n; i++) {
    for (uint64_t j = 1; j <= i; j++) {
      permTable[i][j] = permTable[i - 1][j] + permTable[i - 1][j - 1];
    }
  }
  return permTable;
}

void solve() {
  uint64_t n, m, t;
  cin >> n >> m >> t;

  vector<vector<uint64_t>> pt1 = permutation_table(n);
  vector<vector<uint64_t>> pt2 = permutation_table(m);

  uint64_t j = t - 4, res = 0;
  for (uint64_t i = 4; i <= t - 1; i++, j--) {
    res += (i <= n ? pt1[n][i] : 0) * (j <= m ? pt2[m][j] : 0);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
