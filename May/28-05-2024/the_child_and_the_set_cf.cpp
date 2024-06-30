#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll higest_power_of_2(ll num) {
  ll hpo2 = 1;
  while (hpo2 <= num) {
    hpo2 *= 2;
  }
  hpo2 /= 2;
  return hpo2;
}

void solve() {
  ll sum, limit;
  cin >> sum >> limit;

  vector<pair<ll, ll>> a;
  for (ll i = 1; i <= limit; i++) {
    for (ll j = 0; j <= 31; j++) {
      if (i & (1 << j)) {
        a.push_back({pow(2, j), i});
        break;
      }
    }
  }

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  vector<ll> ans;

  ll i = 0;
  while (i < a.size() && sum > 0) {
    while (sum < a[i].first) {
      i++;
    }
    sum -= a[i].first;
    ans.push_back(a[i].second);
    i++;
  }

  if (sum == 0) {
    cout << ans.size() << endl;
    for (auto j : ans) cout << j << ' ';
    cout << endl;
  } else {
    cout << -1 << endl;
  }
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
