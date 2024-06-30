#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;

  ll a, b;
  if (n % 2 != 0) {
    a = (n * n - 1) / 2;
    b = (n * n + 1) / 2;
  } else {
    a = (n * n - 4) / 4;
    b = (n * n + 4) / 4;
  }

  if (a <= 0 || b <= 0) {
    cout << -1 << endl;
    return;
  }

  cout << a << ' ' << b << endl;
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
