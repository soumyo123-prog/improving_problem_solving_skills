#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, m;
  cin >> n >> m;

  set<ll> st;
  vector<ll> ans(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    st.insert(i);
  }

  for (ll i = 1; i <= m; i++) {
    ll l, r, x;
    cin >> l >> r >> x;
    auto start = st.lower_bound(l), end = st.upper_bound(r);
    stack<set<ll>::iterator> ptrs;
    for (set<ll>::iterator i = start; i != end; i++) {
      if (*i != x) {
        ans[*i] = x;
        ptrs.push(i);
      }
    }
    while (!ptrs.empty()) {
      st.erase(ptrs.top());
      ptrs.pop();
    }
  }

  for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
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
