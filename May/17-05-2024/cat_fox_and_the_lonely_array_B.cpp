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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<vector<int>> cnt(n, vector<int>(20, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      if (i > 0) {
        cnt[i][j] = cnt[i - 1][j];
      }
      if (a[i] & (1 << j)) {
        cnt[i][j]++;
      }
    }
  }

  int l = 1, r = n, ans = n;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    vector<int> t1(20, 0);
    bool flag = true;
    for (int i = 0; i < 20; i++) {
      if (cnt[mid - 1][i] > 0) {
        t1[i] = 1;
      }
    }
    for (int i = 1; i + mid <= n; i++) {
      vector<int> t2(20, 0);
      for (int j = 0; j < 20; j++) {
        if (cnt[i + mid - 1][j] - cnt[i - 1][j] > 0) {
          t2[j] = 1;
        }
      }
      if (t2 != t1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
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
