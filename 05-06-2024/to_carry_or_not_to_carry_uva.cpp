#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(uint32_t a, uint32_t b) {
  ll c = 0;
  for (int i = 0; i < 32; i++) {
    c += ((a & (1 << i) ? 1 : 0) ^ (b & (1 << i) ? 1 : 0)) * (1 << i);
  }
  cout << c << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  uint32_t a, b;
  while (cin >> a >> b) {
    solve(a, b);
  }
  return 0;
}
