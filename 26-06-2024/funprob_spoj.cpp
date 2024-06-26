#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

double find_prob(ll n, ll m) {
  double p = 0;

  if (n > m) p;

  p = double(m + 1 - n) / double(m + 1);
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (1) {
    ll n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    printf("%.6f\n", find_prob(n, m));
  }
  return 0;
}