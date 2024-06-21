#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> c1(n + 1, 0), c2(n + 1, 0);
  bool flag = false;
  int i = 0;
  for (int j = 0; j <= i; j++) {
    c1[a[j]]++;
  }
  for (int j = i + 1; j < n; j++) {
    c2[a[j]]++;
  }

  int m1 = 0, m2 = 0;
  for (int j = 0; j <= n; j++) {
    if (c1[j] == 0) {
      m1 = j;
      break;
    }
  }
  for (int j = 0; j <= n; j++) {
    if (c2[j] == 0) {
      m2 = j;
      break;
    }
  }

  // cout << m1 << ' ' << m2 << endl;

  int l1, r1, l2, r2;

  if (m1 == m2) {
    l1 = 1;
    r1 = 1;
    l2 = 2;
    r2 = n;
    flag = true;
  } else {
    i++;
    while (i < n - 1) {
      c1[a[i]]++;
      c2[a[i]]--;
      if (a[i] == m1) {
        for (int j = m1 + 1; j <= n; j++) {
          if (c1[j] == 0) {
            m1 = j;
            break;
          }
        }
      }
      if (a[i] < m2 && c2[a[i]] == 0) {
        m2 = a[i];
      }
      // cout << m1 << ' ' << m2 << endl;

      if (m1 == m2) {
        l1 = 1;
        r1 = i + 1;
        l2 = r1 + 1;
        r2 = n;
        flag = true;
        break;
      }

      i++;
    }
  }

  if (flag) {
    cout << 2 << endl;
    cout << l1 << ' ' << r1 << endl;
    cout << l2 << ' ' << r2 << endl;
  } else {
    cout << -1 << endl;
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
