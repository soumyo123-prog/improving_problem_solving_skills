#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<ll>> o(m);
  for (ll i = 0; i < m; i++) {
    vector<ll> co(4, 0);
    cin >> co[0] >> co[1] >> co[2];
    co[0]--, co[1]--;
    o[i] = co;
  }

  vector<pair<ll, ll>> q;
  for (ll i = 0; i < k; i++) {
    ll x, y;
    cin >> x >> y;
    q.push_back({x - 1, 1});
    q.push_back({y, -1});
  }
  sort(q.begin(), q.end(), greater<pair<ll, ll>>());

  ll count = 0;
  for (ll i = 0; i < m; i++) {
    while (!q.empty() && q.back().first <= i) {
      count += q.back().second;
      q.pop_back();
    }
    o[i][3] = count;
  }

  vector<vector<ll>> operations(m);
  for (ll i = 0; i < m; i++) {
    operations[i] = {o[i][0], o[i][1], o[i][3] * o[i][2]};
  }

  vector<pair<ll, ll>> seg;
  for (ll i = 0; i < m; i++) {
    seg.push_back({operations[i][0], operations[i][2]});
    seg.push_back({operations[i][1] + 1, -operations[i][2]});
  }
  sort(seg.begin(), seg.end(), greater<pair<ll, ll>>());

  count = 0;
  for (ll i = 0; i < n; i++) {
    while (!seg.empty() && seg.back().first <= i) {
      count += seg.back().second;
      seg.pop_back();
    }
    a[i] += count;
    cout << a[i] << ' ';
  }
  cout << endl;
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
