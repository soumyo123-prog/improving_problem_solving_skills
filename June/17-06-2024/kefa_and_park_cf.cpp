#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> cats(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> cats[i];
  }
  vector<ll> tempAdj[n + 1];
  for (ll i = 1; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    tempAdj[x].push_back(y);
    tempAdj[y].push_back(x);
  }

  queue<vector<ll>> q;
  q.push({1, cats[1], cats[1]});
  vector<bool> vis(n + 1, false);
  vis[1] = true;

  ll ans = 0;
  while (!q.empty()) {
    vector<ll> u = q.front();
    q.pop();

    bool flag = false;
    for (auto i : tempAdj[u[0]]) {
      if (!vis[i]) {
        flag = true;
        ll cc = cats[i] == 0 ? 0 : u[1] + cats[i];
        q.push({i, cc, max(cc, u[2])});
        vis[i] = true;
      }
    }

    if (!flag && u[2] <= m) {
      ans++;
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