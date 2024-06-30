#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m;
  cin >> n >> m;

  double leftProb = 0, rightProb = 0;
  ll leftNum = m, rightNum = m;

  if (m > 1) {
    leftProb = (double)m / n;
    leftNum = m - 1;
  }

  if (m < n) {
    rightProb = (double)(n - m + 1) / n;
    rightNum = m + 1;
  }

  if (leftProb >= rightProb)
    cout << leftNum << endl;
  else
    cout << rightNum << endl;
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
