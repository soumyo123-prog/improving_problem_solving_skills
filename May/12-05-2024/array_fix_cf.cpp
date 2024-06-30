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

  vector<int> b;

  bool flag = true;

  b.push_back(a[n - 1]);
  int ptr = 0;

  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > b[ptr]) {
      if (a[i] >= 10) {
        int ud = a[i] % 10, td = a[i] / 10;
        if (td <= ud) {
          if (ud <= b[ptr]) {
            b.push_back(ud);
            b.push_back(td);
            ptr += 2;
          } else {
            flag = false;
            break;
          }
        } else {
          flag = false;
          break;
        }
      } else {
        flag = false;
        break;
      }
    } else {
      b.push_back(a[i]);
      ptr++;
    }
  }

  if (!flag) {
    printYesOrNo(flag);
  } else {
    for (int i = 1; i < b.size(); i++) {
      if (b[i] > b[i - 1]) {
        flag = false;
        break;
      }
    }
    printYesOrNo(flag);
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
