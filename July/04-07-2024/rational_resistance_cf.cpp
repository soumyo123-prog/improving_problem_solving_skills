#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll a, b;
  cin >> a >> b;

  ll step = 1;
  while (a > 1 || b > 1) {
    if (a > b) {
      step += ceil((double)(a - b) / b);
      a = a % b;
    } else {
      step += ceil((double)(b - a) / a);
      b = b % a;
    }
  }

  cout << step << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
