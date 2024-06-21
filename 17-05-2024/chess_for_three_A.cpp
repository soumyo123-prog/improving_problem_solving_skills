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
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  int oc = 0, ec = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i] % 2 == 0)
      ec++;
    else
      oc++;
  }

  if (oc == 3 || oc == 1) {
    cout << -1 << endl;
    return;
  }

  int ans = 0;
  while (a[2] > 0 && a[1] > 0) {
    ans++;
    a[2]--;
    a[1]--;
    sort(a.begin(), a.end());
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
