#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int t1 = a * a;
  int t2 = c * c;
  int t3 = e * e;

  int t = (d + e + c) * (d + e + c);
  int h = t - (t1 + t2 + t3);

  cout << h << endl;
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
