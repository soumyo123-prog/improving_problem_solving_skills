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
  vector<pair<int, int>> xy(n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    int xi, yi;
    cin >> xi >> yi;
    xy[i] = {xi, yi};
    x[i] = xi;
    y[i] = yi;
  }

  sort(xy.begin(), xy.end());
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll xp = 0, yp = 0, tp = 0, cnt = 1;

  for (int i = 1; i < n; i++) {
    if (x[i] == x[i - 1]) {
      cnt++;
    } else {
      xp += ((cnt * (cnt - 1)) / 2);
      cnt = 1;
    }
  }
  xp += ((cnt * (cnt - 1)) / 2);

  cnt = 1;
  for (int i = 1; i < n; i++) {
    if (y[i] == y[i - 1]) {
      cnt++;
    } else {
      yp += ((cnt * (cnt - 1)) / 2);
      cnt = 1;
    }
  }
  yp += ((cnt * (cnt - 1)) / 2);

  cnt = 1;
  for (int i = 1; i < n; i++) {
    if (xy[i].first == xy[i - 1].first && xy[i].second == xy[i - 1].second) {
      cnt++;
    } else {
      tp += ((cnt * (cnt - 1)) / 2);
      cnt = 1;
    }
  }
  tp += ((cnt * (cnt - 1)) / 2);

  cout << xp + yp - tp << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
