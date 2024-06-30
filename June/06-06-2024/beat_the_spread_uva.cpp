#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll s, d;
  cin >> s >> d;

  ll a = (s + d) / 2LL, b = (s - d) / 2LL;
  if (a >= 0 && b >= 0 && a + b == s && a - b == d) {
    cout << a << ' ' << b << endl;
  } else {
    cout << "impossible" << endl;
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
