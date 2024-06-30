#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll diff(ll p, vector<ll> p1) {
  ll num = 0;
  for (auto i : p1) num = num * 10 + i;
  return p - num;
}

void solve() {
  ll p, d;
  cin >> p >> d;

  vector<ll> p1;
  ll tempP = p;
  while (tempP > 0) {
    p1.push_back(tempP % 10);
    tempP /= 10;
  }
  reverse(p1.begin(), p1.end());

  int i = p1.size() - 1;
  while (i > 0) {
    if (p1[i] == 9) {
      i--;
      continue;
    }
    vector<ll> p2 = p1;
    p2[i] = 9;
    i--;
    while (i >= 0 && p2[i] == 0) {
      p2[i] = 9;
      i--;
    }
    if (i >= 0) {
      p2[i] = p2[i] - 1;
    }
    ll difference = diff(p, p2);
    if (difference <= d) {
      p1 = p2;
    } else {
      break;
    }
  }

  ll ans = 0;
  for (auto j : p1) ans = ans * 10 + j;
  cout << ans << endl;
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
