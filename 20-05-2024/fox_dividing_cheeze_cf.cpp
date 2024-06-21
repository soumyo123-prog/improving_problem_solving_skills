#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primeFactors(int n) {
  vector<int> res;
  while (n % 2 == 0) {
    res.push_back(2);
    n /= 2;
  }
  while (n % 3 == 0) {
    res.push_back(3);
    n /= 3;
  }
  while (n % 5 == 0) {
    res.push_back(5);
    n /= 5;
  }

  if (n != 1) {
    res.push_back(n);
  }
  return res;
}

void solve() {
  int a, b;
  cin >> a >> b;

  int gcd = __gcd(a, b);

  int i1 = a / gcd, i2 = b / gcd;

  vector<int> pf1 = primeFactors(i1), pf2 = primeFactors(i2);
  for (int i : pf1) {
    if (!(i == 2 || i == 3 || i == 5)) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i : pf2) {
    if (!(i == 2 || i == 3 || i == 5)) {
      cout << -1 << endl;
      return;
    }
  }
  cout << pf1.size() + pf2.size() << endl;
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
