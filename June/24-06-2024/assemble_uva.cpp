#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, b;
  cin >> n >> b;

  map<string, vector<pair<ll, ll>>> inp;
  for (ll i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    ll p, q;
    cin >> p >> q;
    inp[s1].push_back({p, q});
  }

  ll start = 0, end = 1000000000, ans = 0;
  while (start <= end) {
    ll mid = start + (end - start) / 2;

    ll totp = 0;
    bool of = true;

    for (auto i : inp) {
      ll lp = LLONG_MAX;
      bool f = false;

      for (pair<ll, ll> j : i.second) {
        if (j.second >= mid && j.first <= lp) {
          f = true;
          lp = j.first;
        }
      }

      if (f) {
        totp += lp;
      } else {
        of = false;
        break;
      }
    }

    if (!of) {
      end = mid - 1;
    } else {
      if (totp <= b) {
        ans = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
