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

void print_array(vector<int> a) {
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << endl;
}

void solve() {
  int n;
  cin >> n;

  if (n % 2 == 0) {
    cout << -1 << endl;
    return;
  }

  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
    c[i] = (a[i] + b[i]) % n;
  }

  print_array(a);
  print_array(b);
  print_array(c);
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
