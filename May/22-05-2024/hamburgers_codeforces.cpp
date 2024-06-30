#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool check(ll rb, ll rs, ll rc, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc,
           ll r) {
  if (rb > nb) r = r - (rb - nb) * pb;
  if (rs > ns) r = r - (rs - ns) * ps;
  if (rc > nc) r = r - (rc - nc) * pc;
  if (r >= 0) return true;
  return false;
}

void solve() {
  string s;
  cin >> s;

  ll nbu = 0, nsu = 0, ncu = 0;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == 'B')
      nbu++;
    else if (s[i] == 'S')
      nsu++;
    else
      ncu++;
  }

  ll nb, ns, nc, pb, ps, pc, r;
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

  ll left = 0, right = 1e13, ans = 0;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (check(nbu * mid, nsu * mid, ncu * mid, nb, ns, nc, pb, ps, pc, r)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

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
