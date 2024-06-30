#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(uint64_t n) {
  uint64_t den = n * (n + 1);
  uint64_t x = 2;
  uint64_t rt = den / x;
  uint64_t sq = rt * rt;
  cout << sq << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  uint64_t n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
