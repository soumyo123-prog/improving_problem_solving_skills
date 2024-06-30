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
  vector<string> a(2);
  cin >> a[0];
  cin >> a[1];

  bool flag = true;
  int i = 1, j = 1;
  while (1) {
    if (i == 1 && j == n - 1) break;
    if (i == 0) {
      if (a[i][j + 1] == '>') {
        j += 2;
      } else {
        if (a[i + 1][j] == '>') {
          i++;
          j++;
        } else {
          flag = false;
          break;
        }
      }
    } else {
      if (a[i][j + 1] == '>') {
        j += 2;
      } else {
        if (a[i - 1][j] == '>') {
          i--;
          j++;
        } else {
          flag = false;
          break;
        }
      }
    }
  }

  printYesOrNo(flag);
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
