#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    string yes = "YES";
    string no = "NO";

    if (a[0][0] == a[n - 1][m - 1] || a[0][m - 1] == a[n - 1][0]) {
      cout << yes << endl;
    } else {
      bool f1 = false, f2 = false;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i][m - 1] == a[0][0]) {
          f1 = true;
          break;
        }
      }
      for (int i = m - 2; i >= 0; i--) {
        if (a[n - 1][i] == a[0][0]) {
          f2 = true;
          break;
        }
      }
      if (f1 && f2) {
        cout << yes << endl;
      } else {
        bool f3 = 0, f4 = 0;
        for (int i = 1; i < n; i++) {
          if (a[i][0] == a[n - 1][m - 1]) {
            f3 = 1;
            break;
          }
        }
        for (int i = 1; i < m; i++) {
          if (a[0][i] == a[n - 1][m - 1]) {
            f4 = 1;
            break;
          }
        }
        if (f3 && f4) {
          cout << yes << endl;
        } else {
          cout << no << endl;
        }
      }
    }
  }

  return 0;
}